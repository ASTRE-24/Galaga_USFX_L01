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
    FVector ubicacionInicioNavesEnemigas = FVector(1850.0f, -1540.7f, 250.0f);
    FVector ubicacionInicioNavesEnemigasTransporte = FVector(500.0f, 500.0f, 250.0f);
    FVector ubicacionDeObjetosInventario = FVector(-700.0f, 300.0f, 700.0f);
    FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);
    FRotator rotacionNave90 = FRotator(0.0f, 90.0f, 0.0f);
    
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
        //for (int i = 0; i < 6; i++) {
        //    //Esto es para crear las naves enemigas en una ubicacion especifica para comenzar
        //    FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 600.0f, ubicacionInicioNavesEnemigas.Z);
        //    
        //    for (int j = 0; j < 5; j++) {
        //        FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);
        //        //PosicionesNavesEnemigas.Add(j, PosicionNaveActualY);//Agrega la posicion de la nave al TMap
        //        ANaveEnemiga* NaveEnemigaTemporal = nullptr; // Crear un puntero a nave enemiga

        //        // Generar un número aleatorio entre 0 y 1
        //        float RandomNumber = FMath::FRandRange(0.0f, 1.0f);

        //        // Probabilidad de generar una nave caza o transporte (50% cada una)
        //        if (RandomNumber <= 0.5f) {
        //            NaveEnemigaTemporal = World->SpawnActor<ANaveReabastecimientoMunicion>(PosicionNaveActualY, rotacionNave); // Spawn nave caza
        //        }
        //        else {
        //            NaveEnemigaTemporal = World->SpawnActor<ANaveReabastecimientoEnergia>(PosicionNaveActualY, rotacionNave); // Spawn nave transporte
        //        }

        //        if (NaveEnemigaTemporal != nullptr) {
        //            NaveEnemigas.Add(GetUniqueNameForNave(), NaveEnemigaTemporal); // Agregar nave al TMap
        //        }
        //    }
        //}
        //TiempoTranscurrido = 0;

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

        

        for (int i = 0; i < 6; i++) {
            FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 600.0f, ubicacionInicioNavesEnemigas.Z);

            for (int j = 0; j < 1; j++) {
                FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);

                // Selecciona un tipo de nave aleatorio
                int32 RandomIndex = FMath::RandRange(0, TiposDeNaves.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
                TSubclassOf<ANaveEnemiga> NaveClass = TiposDeNaves[RandomIndex]; //Selecciona una subclase de ANaveEnemiga aleatoria

                // Spawnea la nave aleatoria
                ANaveEnemiga* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemiga>(NaveClass, PosicionNaveActualY, rotacionNave);//Spawnea la nave enemiga en una posicion y rotacion especifica

                if (NaveEnemigaTemporal != nullptr) {
                    NaveEnemigas.Add(GetUniqueNameForNave(), NaveEnemigaTemporal);// Agregar nave al TMap
                }
            }
        }
        TiempoTranscurrido = 0;

        //Para el spauwn de las objetos de inventario
        for (int i = 0; i < 6; i++) {
			UbicacionInventario.Add(i, FVector(ubicacionDeObjetosInventario.X, ubicacionDeObjetosInventario.Y + i * 100.0f, ubicacionDeObjetosInventario.Z));
             //Generar un número aleatorio entre 0 y 1
                float RandomNumber = FMath::FRandRange(0.0f, 1.0f);

                // Probabilidad de generar una nave caza o transporte (50% cada una)
                if (RandomNumber <= 0.5f) {
                    AInventoryActor* ObjetoInventario = World->SpawnActor<AInventoryActor>(AInventoryActorMunicion::StaticClass(), UbicacionInventario[i], rotacionNave);
                    //Spawnea el objeto de inventario en una posicion y rotacion especifica  
                    
                }
                else {
                    AInventoryActor* ObjetoInventario = World->SpawnActor<AInventoryActor>(AInventoryActorEnergia::StaticClass(), UbicacionInventario[i], rotacionNave);
                    //Spawnea el objeto de inventario en una posicion y rotacion especifica  
                    
                }
               // FString UbInventarioString = FString::Printf(TEXT("X: %f, Y: %f, Z: %f"), UbicacionInventario[i].X, UbicacionInventario[i].Y, UbicacionInventario[i].Z);
                //FString Message = FString::Printf(TEXT("Tienes %d objetos en tu inventario"), UbicacionInventario[i]);
               // GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue, UbInventarioString);

                //if (i == 2) {
                   // UbicacionInventario[2] = FVector(0.0,0.0,0.0);
                   // FString UbInventarioString2 = FString::Printf(TEXT(" Se cambio a X: %f, Y: %f, Z: %f"), UbicacionInventario[2].X, UbicacionInventario[2].Y, UbicacionInventario[2].Z);
                    //FString Mensaje = FString::Printf(TEXT("Tienes %d objetos en tu inventario"), UbicacionInventario[2]);  
                    //FString Message = FString::Printf(TEXT("Tienes %d objetos en tu inventario"), UbicacionInventario[i]);
                   // GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, UbInventarioString+UbInventarioString2);
                //}

		}
        UbicacionInventario.Remove(4);
        //if (!UbicacionInventario.Contains(4))
        //GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "Se elimino la ubicacion 5");
        
    }
    //Llama a la funcion NaveInvisible cada 5 segundos
    FTimerHandle TimerHandle_NaveInvisible;
    GetWorldTimerManager().SetTimer(TimerHandle_NaveInvisible, this, &AGalaga_USFX_L01GameMode::NaveInvisible, 5.0f, true);
}

FString AGalaga_USFX_L01GameMode::GetUniqueNameForNave()
{
    static int32 Counter = 0;
    if (GEngine)
    {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("NaveEnemiga_%d"), Counter));
	}
    return FString::Printf(TEXT("NaveEnemiga_%d"), Counter++);
}

//hacer que una nave enemiga aleatoria sea invisble cada 5 segundos
void AGalaga_USFX_L01GameMode::NaveInvisible()
{
	int32 RandomIndex = FMath::RandRange(0, NaveEnemigas.Num()-1);//Genera un numero aleatorio entre 1 y el tamaño del TMap
    NaveEnemigas[FString::Printf(TEXT("NaveEnemiga_%d"), RandomIndex)]->SetActorHiddenInGame(true);//Hace invisible la nave enemiga
    //Llama a la funcion HacerVisible cada 2 segundos

    FTimerHandle TimerHandle_HacerVisible;
   //GetWorldTimerManager().SetTimer(TimerHandle_HacerVisible, this, &AGalaga_USFX_L01GameMode::HacerVisible, 2.0f, false, RandomIndex);
}

void AGalaga_USFX_L01GameMode::HacerVisible(int32 Llave)
{
    	//sssNaveEnemigas[Llave]->SetActorHiddenInGame(false);//Hace visible la nave enemiga
}



