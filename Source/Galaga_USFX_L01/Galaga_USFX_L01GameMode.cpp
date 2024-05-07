// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01GameMode.h"
#include "Galaga_USFX_L01Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaCazaSigilosa.h"
#include "NaveEnemigaCazaVeloz.h"
#include "NaveEnemigaTransporteFurtivo.h"
#include "NaveEnemigaTransporteLogistico.h"
#include "NaveEnemigaEspiaInfiltrada.h"
#include "NaveEnemigaEspiaTactica.h"
#include "NaveEnemigaNodrizaBlindada.h"
#include "NaveEnemigaNodrizaTactico.h"
#include "NaveReabastecimientoEnergia.h"
#include "NaveReabastecimientoMunicion.h"
#include "InventoryActor.h"
#include "InventoryActorEnergia.h"
#include "InventoryActorMunicion.h"
#include "SolicitudDeNavesApoyo.h"
#include "SolicitudDeNavesAtaque.h"
#include "SolicitudDeNavesInformante.h"
#include "JugadorCapsula.h"
#include "EnemigoCapsula.h"
#include "BuilderConcretoPNReparar.h"
#include "DirectorPortaNave.h"
#include "PortaNave.h"
#include "DirectorNaveNodriza.h"
#include "BuilderNaveNodrizaFase1.h"
#include "BuilderNaveNodrizaFase2.h"
#include "BuilderNaveNodrizaFase3.h"
#include "TimerManager.h"

AGalaga_USFX_L01GameMode::AGalaga_USFX_L01GameMode()
{
	// set default pawn class to our character class
	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = AGalaga_USFX_L01Pawn::StaticClass();

	//NaveEnemiga01 = nullptr;
}

void AGalaga_USFX_L01GameMode::BeginPlay()
{
    Super::BeginPlay();
    //Set the game state to playing
    FVector ubicacionInicioNavesEnemigas = FVector(1850.0f, -1540.7f, 216.0f);
    FVector ubicacionInicioNavesEnemigasTransporte = FVector(500.0f, 500.0f, 250.0f);
    FVector ubicacionDeObjetosInventario = FVector(-700.0f, 300.0f, 700.0f);
    FRotator rotacionNave = FRotator(0.0f, 180.0f, 0.0f);
    FRotator rotacionNave90 = FRotator(0.0f, 90.0f, 0.0f);

	
    ReparacionPorta = GetWorld()->SpawnActor<ABuilderConcretoPNReparar>(ABuilderConcretoPNReparar::StaticClass());
    IngenieroPortaNave = GetWorld()->SpawnActor<ADirectorPortaNave>(ADirectorPortaNave::StaticClass());
    IngenieroPortaNave->SetBuilderPortaNave(ReparacionPorta);
    IngenieroPortaNave->ConstruirPortaNave();

	DirectorNodriza = GetWorld()->SpawnActor<ADirectorNaveNodriza>(ADirectorNaveNodriza::StaticClass());
	BuilderNodrizaFase1 = GetWorld()->SpawnActor<ABuilderNaveNodrizaFase1>(ABuilderNaveNodrizaFase1::StaticClass());
	BuilderNodrizaFase2 = GetWorld()->SpawnActor<ABuilderNaveNodrizaFase2>(ABuilderNaveNodrizaFase2::StaticClass());
	BuilderNodrizaFase3 = GetWorld()->SpawnActor<ABuilderNaveNodrizaFase3>(ABuilderNaveNodrizaFase3::StaticClass());
	DirectorNodriza->enviarConstructor(BuilderNodrizaFase1);
	DirectorNodriza->construirNaveNodriza();
    ANaveEnemigaNodriza* NaveNodriza = DirectorNodriza->obtenerNave();
    DirectorNodriza->enviarConstructor(BuilderNodrizaFase2);
    DirectorNodriza->construirNaveNodriza();
    ANaveEnemigaNodriza* NaveNodriza2 = DirectorNodriza->obtenerNave();
    DirectorNodriza->enviarConstructor(BuilderNodrizaFase3);
    DirectorNodriza->construirNaveNodriza();
	ANaveEnemigaNodriza* NaveNodriza3 = DirectorNodriza->obtenerNave();
	posicionCapsulasEnemigas = NaveNodriza->GetPosicionesNaves();
	NavesEnemigas = NaveNodriza->GetNavesEnemigas();

    //Creacion de los distintos tipos de capsulas
    InventarioAB = GetWorld()->SpawnActor<IInventarioAFactory>(AJugadorCapsula::StaticClass());
    for (int i = 0; i < 7; i++) {
        UbicacionInventario.Add(i, FVector(ubicacionDeObjetosInventario.X, ubicacionDeObjetosInventario.Y + i * 140.0f, ubicacionDeObjetosInventario.Z));
        //Generar un número aleatorio entre 0 y 1
        int RandomNumber = FMath::FRandRange(0, 3);
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Numero aleatorio: %d"), RandomNumber));
        if (RandomNumber == 0)
        {
            InventarioAB->crearCapsulaArma(UbicacionInventario[i]);
        }
        else if (RandomNumber == 1)
        {
            InventarioAB->crearCapsulaEnergia(UbicacionInventario[i]);
        }
        else if (RandomNumber == 2)
        {
            InventarioAB->crearCapsulaMunicion(UbicacionInventario[i]);
        }

    }

    InventarioAB = GetWorld()->SpawnActor<IInventarioAFactory>(AEnemigoCapsula::StaticClass());
	GetWorldTimerManager().SetTimer(TimerCapsulas, this, &AGalaga_USFX_L01GameMode::SapwnCapsulasEnemigas, 10.0f, true);


    APortaNave* portal = IngenieroPortaNave->GetPortaNave();
    portal->caracteristicas();

    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        // Ajusta las propiedades del controlador del jugador
        PlayerController->bShowMouseCursor = true;
        PlayerController->bEnableClickEvents = true;
        PlayerController->bEnableMouseOverEvents = true;
    }

    UWorld* const World = GetWorld();
    if (World != nullptr)
    {
    //    //Creacion de las solicitudes de naves
    //    ASolicitudDeNaves* SolicitudDeNavesAtaque = World->SpawnActor<ASolicitudDeNavesAtaque>(ASolicitudDeNavesAtaque::StaticClass());
    //    ASolicitudDeNaves* SolicitudDeNavesApoyo = World->SpawnActor<ASolicitudDeNavesApoyo>(ASolicitudDeNavesApoyo::StaticClass());
    //    ASolicitudDeNaves* SolicitudDeNavesInformante = World->SpawnActor<ASolicitudDeNavesInformante>(ASolicitudDeNavesInformante::StaticClass());

    //    

    //    //Aniadir los nombres al TArray
    //    NombresNavesAtaque.Add("NaveEnemigaCaza");
    //    NombresNavesAtaque.Add("NaveEnemigaCazaSigilosa");
    //    NombresNavesAtaque.Add("NaveEnemigaCazaVeloz");
    //    NombresNavesApoyo.Add("NaveEnemigaTransporte");
    //    NombresNavesApoyo.Add("NaveEnemigaTransporteFurtivo");
    //    NombresNavesApoyo.Add("NaveEnemigaTransporteLogistico");
    //    NombresNavesInformante.Add("NaveEnemigaEspia");
    //    NombresNavesInformante.Add("NaveEnemigaEspiaInfiltrada");
    //    NombresNavesInformante.Add("NaveEnemigaEspiaTactica");
    //    NombresNavesApoyo.Add("NaveEnemigaNodriza");
    //    NombresNavesApoyo.Add("NaveEnemigaNodrizaBlindada");
    //    NombresNavesApoyo.Add("NaveEnemigaNodrizaTactico");
    //    NombresNavesApoyo.Add("NaveEnemigaReabastecimiento");
    //    NombresNavesApoyo.Add("NaveReabastecimientoEnergia");
    //    NombresNavesApoyo.Add("NaveReabastecimientoMunicion");
    //    
    //    

    //    //Creacion de las naves enemigas

    //    for (int i = 0; i < 6; i++) {
    //        FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 600.0f, ubicacionInicioNavesEnemigas.Z);

    //        for (int j = 0; j < 3; j++) {
    //            FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);
    //            
    //            // Selecciona un tipo de nave aleatorio
    //            int32 CategoriaNave = 0;//FMath::RandRange(0, CategoriasNaves.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
    //            if (CategoriaNave == 0)
    //            {
    //                int32 RandomIndex = FMath::RandRange(0, NombresNavesAtaque.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
    //                // Spawnea la nave aleatoria
    //                ANaveEnemiga* NaveEnemigaAtaque = SolicitudDeNavesAtaque->OrdenarNaveEnemiga(NombresNavesAtaque[RandomIndex], PosicionNaveActualY, rotacionNave);
    //                if (j == 2) NaveEnemigaAtaque->bShoulDispara = true;
    //            }
    //            else if (CategoriaNave == 1)
    //            {
				//	int32 RandomIndex = FMath::RandRange(0, NombresNavesApoyo.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
				//	// Spawnea la nave aleatoria
				//	ANaveEnemiga* NaveEnemigaApoyo = SolicitudDeNavesApoyo->OrdenarNaveEnemiga(NombresNavesApoyo[RandomIndex], PosicionNaveActualY, rotacionNave);
    //                if (j == 2) NaveEnemigaApoyo->bShoulDispara = true;
				//}
    //            else if (CategoriaNave == 2)
    //            {
				//	int32 RandomIndex = FMath::RandRange(0, NombresNavesInformante.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
				//	// Spawnea la nave aleatoria
				//	ANaveEnemiga* NaveEnemigaInformante = SolicitudDeNavesInformante->OrdenarNaveEnemiga(NombresNavesInformante[RandomIndex], PosicionNaveActualY, rotacionNave);
    //                if (j == 2) NaveEnemigaInformante->bShoulDispara = true;
				//}

    //        }
    //    }
        

        // Tipos de naves disponibles
        TArray<TSubclassOf<ANaveEnemiga>> TiposDeNaves;//Crea un TArray de subclases de ANaveEnemiga
        TiposDeNaves.Add(ANaveEnemigaCaza::StaticClass()); //Agrega la subclase ANaveEnemigaCaza al TArray
        /*TiposDeNaves.Add(ANaveEnemigaCazaVeloz::StaticClass());
        TiposDeNaves.Add(ANaveEnemigaCazaSigilosa::StaticClass());
        TiposDeNaves.Add(ANaveEnemigaTransporte::StaticClass());
        TiposDeNaves.Add(ANaveEnemigaTransporteFurtivo::StaticClass());
        TiposDeNaves.Add(ANaveEnemigaTransporteLogistico::StaticClass());
        TiposDeNaves.Add(ANaveEnemigaEspia::StaticClass());
        TiposDeNaves.Add(ANaveEnemigaEspiaInfiltrada::StaticClass());
        TiposDeNaves.Add(ANaveEnemigaEspiaTactica::StaticClass());
        TiposDeNaves.Add(ANaveEnemigaNodriza::StaticClass());
        TiposDeNaves.Add(ANaveEnemigaNodrizaBlindada::StaticClass());
        TiposDeNaves.Add(ANaveEnemigaNodrizaTactico::StaticClass());
        TiposDeNaves.Add(ANaveEnemigaReabastecimiento::StaticClass());
        TiposDeNaves.Add(ANaveReabastecimientoEnergia::StaticClass());
        TiposDeNaves.Add(ANaveReabastecimientoMunicion::StaticClass());*/

        

        //for (int i = 0; i < 6; i++) {
        //    FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 600.0f, ubicacionInicioNavesEnemigas.Z);

        //    for (int j = 0; j < 1; j++) {
        //        FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);

        //        // Selecciona un tipo de nave aleatorio
        //        int32 RandomIndex = FMath::RandRange(0, TiposDeNaves.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
        //        TSubclassOf<ANaveEnemiga> NaveClass = TiposDeNaves[RandomIndex]; //Selecciona una subclase de ANaveEnemiga aleatoria

        //        // Spawnea la nave aleatoria
        //       ANaveEnemiga* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemiga>(NaveClass, PosicionNaveActualY, rotacionNave);//Spawnea la nave enemiga en una posicion y rotacion especifica

        //        if (NaveEnemigaTemporal != nullptr) {
        //            NaveEnemigas.Add(GetUniqueNameForNave(), NaveEnemigaTemporal);// Agregar nave al TMap
        //        }
        //    }
        //}
        TiempoTranscurrido = 0;
    }
    
}

FString AGalaga_USFX_L01GameMode::GetUniqueNameForNave()
{
    static int32 Counter = 0;
    
    return FString::Printf(TEXT("NaveEnemiga_%d"), Counter++);
}

void AGalaga_USFX_L01GameMode::SapwnCapsulasEnemigas()
{
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
        for (int i = 0; i < NavesEnemigas.Num(); i++) {
            
            int RandomNumber = FMath::FRandRange(0, 3);
			FVector PosicionNaveActual = posicionCapsulasEnemigas[i] + FVector(0.0f, 0.0f, 500.0f);
            if (RandomNumber == 0)
            {
                InventarioAB->crearCapsulaArma(PosicionNaveActual);
            }
            else if (RandomNumber == 1)
            {
                InventarioAB->crearCapsulaEnergia(PosicionNaveActual);
            }
            else if (RandomNumber == 2)
            {
                InventarioAB->crearCapsulaMunicion(PosicionNaveActual);
            }

        }
	}
}



