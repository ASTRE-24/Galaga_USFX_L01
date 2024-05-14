// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnFacade.h"
#include "ObstaculoMeteoro.h"
#include "ObstaculoPared.h"

// Sets default values
ASpawnFacade::ASpawnFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnFacade::BeginPlay()
{
	Super::BeginPlay();
	posiciones();
}

// Called every frame
void ASpawnFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnFacade::invocarNaves()
{
    navesApoyo = GetWorld()->SpawnActor<ASolicitudDeNavesApoyo>(ASolicitudDeNavesApoyo::StaticClass());
    navesAtaque = GetWorld()->SpawnActor<ASolicitudDeNavesAtaque>(ASolicitudDeNavesAtaque::StaticClass());
    navesInformante = GetWorld()->SpawnActor<ASolicitudDeNavesInformante>(ASolicitudDeNavesInformante::StaticClass());
    //Aniadir los nombres al TArray
    TArray<FString> NombresNavesAtaque;
    TArray<FString> NombresNavesApoyo;
    TArray<FString> NombresNavesInformante;
    NombresNavesAtaque.Add("NaveEnemigaCaza");
    NombresNavesAtaque.Add("NaveEnemigaCazaSigilosa");
    NombresNavesAtaque.Add("NaveEnemigaCazaVeloz");
    NombresNavesApoyo.Add("NaveEnemigaTransporte");
    NombresNavesApoyo.Add("NaveEnemigaTransporteFurtivo");
    NombresNavesApoyo.Add("NaveEnemigaTransporteLogistico");
    NombresNavesInformante.Add("NaveEnemigaEspia");
    NombresNavesInformante.Add("NaveEnemigaEspiaInfiltrada");
    NombresNavesInformante.Add("NaveEnemigaEspiaTactica");
    NombresNavesApoyo.Add("NaveEnemigaReabastecimiento");
    NombresNavesApoyo.Add("NaveReabastecimientoEnergia");
    NombresNavesApoyo.Add("NaveReabastecimientoMunicion");


    UWorld* const World = GetWorld();
    if (World != nullptr)
    {
        //Creacion de las naves enemigas

        for (int i = 0; i < PosicionesNaves.Num(); i++) {
            // Selecciona un tipo de nave aleatorio

            int random = FMath::RandRange(0, 2);
            if (random == 0)
            {
                int32 RandomIndex = FMath::RandRange(0, NombresNavesAtaque.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
                ANaveEnemiga* NaveEnemigaAtaque = navesAtaque->OrdenarNaveEnemiga(NombresNavesAtaque[RandomIndex]);
				NaveEnemigaAtaque->SetActorLocationAndRotation(PosicionesNaves[i], FRotator(0,180,0));
                navesEnemigas.Add(NaveEnemigaAtaque);
            }
            else if (random == 1)
            {
                int32 RandomIndex = FMath::RandRange(0, NombresNavesApoyo.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
                // Spawnea la nave aleatoria
                ANaveEnemiga* NaveEnemigaApoyo = navesApoyo->OrdenarNaveEnemiga(NombresNavesApoyo[RandomIndex]);
				NaveEnemigaApoyo->SetActorLocationAndRotation(PosicionesNaves[i], FRotator(0, 180, 0));
                navesEnemigas.Add(NaveEnemigaApoyo);
            }
            else
            {
                int32 RandomIndex = FMath::RandRange(0, NombresNavesInformante.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
                // Spawnea la nave aleatoria
                ANaveEnemiga* NaveEnemigaInformante = navesInformante->OrdenarNaveEnemiga(NombresNavesInformante[RandomIndex]);
				NaveEnemigaInformante->SetActorLocationAndRotation(PosicionesNaves[i], FRotator(0, 180, 0));
                navesEnemigas.Add(NaveEnemigaInformante);
            }
        }
    }

}

void ASpawnFacade::invocarObstaculos()
{
    FVector ubicacionDeObjetosInventario = FVector(-700.0f, -1300.0f, 215.0f);
	for (int i = 0; i <= 5;i++) {
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			//Generar un número aleatorio entre 0 y 2
			int RandomNumber = FMath::FRandRange(0, 2);
			if (RandomNumber == 0)
			{
				obstaculoMapa = GetWorld()->SpawnActor<AObstaculo>(AObstaculoMeteoro::StaticClass());
				obstaculoMapa->SetActorLocation(ubicacionDeObjetosInventario);
				obstaculos.Add(obstaculoMapa);
			}
			else if (RandomNumber == 1)
			{
				obstaculoMapa = GetWorld()->SpawnActor<AObstaculo>(AObstaculoPared::StaticClass());
				obstaculoMapa->SetActorLocation(ubicacionDeObjetosInventario);
				obstaculos.Add(obstaculoMapa);
			}
		}
		ubicacionDeObjetosInventario = ubicacionDeObjetosInventario + FVector(0.0f, 300.0f, 0.0f);
	}
}

void ASpawnFacade::invocarCapsula()
{
    FVector ubicacionDeObjetosInventario = FVector(-700.0f, 300.0f, 700.0f);
    inventarioFactory = GetWorld()->SpawnActor<IInventarioAFactory>(AJugadorCapsula::StaticClass());
    for (int i = 0; i < 7; i++) {
        UbicacionInventario.Add(i, FVector(ubicacionDeObjetosInventario.X, ubicacionDeObjetosInventario.Y + i * 140.0f, ubicacionDeObjetosInventario.Z));
        //Generar un número aleatorio entre 0 y 1
        int RandomNumber = FMath::FRandRange(0, 3);
        if (RandomNumber == 0)
        {
            inventarioFactory->crearCapsulaArma(UbicacionInventario[i]);
        }
        else if (RandomNumber == 1)
        {
            inventarioFactory->crearCapsulaEnergia(UbicacionInventario[i]);
        }
        else if (RandomNumber == 2)
        {
            inventarioFactory->crearCapsulaMunicion(UbicacionInventario[i]);
        }
    }
    inventarioFactory = GetWorld()->SpawnActor<IInventarioAFactory>(AEnemigoCapsula::StaticClass());
    for (int i = 0; i < navesEnemigas.Num(); i++) {

        int RandomNumber = FMath::FRandRange(0, 3);
        FVector PosicionNaveActual = PosicionesNaves[i] + FVector(0.0f, 0.0f, 500.0f);
        if (RandomNumber == 0)
        {
            inventarioFactory->crearCapsulaArma(PosicionNaveActual);
        }
        else if (RandomNumber == 1)
        {
            inventarioFactory->crearCapsulaEnergia(PosicionNaveActual);
        }
        else if (RandomNumber == 2)
        {
            inventarioFactory->crearCapsulaMunicion(PosicionNaveActual);
        }

    }
}

void ASpawnFacade::realizaTareas()
{
}

void ASpawnFacade::posiciones()
{
    int formacion = FMath::RandRange(1, 3); //Genera un numero aleatorio entre 1 y 3
    FVector ubicacionInicioNavesEnemigas = FVector(1850.0f, -1540.7f, 216.0f);
    if (formacion == 1)
    {
        for (int i = 0; i < 6; i++) {
            FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 600.0f, ubicacionInicioNavesEnemigas.Z);

            for (int j = 0; j < 3; j++) {
                FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);
                if ((i == 0 || i == 5) && j == 0)
                    PosicionesNaves.Add(PosicionNaveActualY);
                if ((i == 1 || i == 4) && (j == 0 || j == 1))
                    PosicionesNaves.Add(PosicionNaveActualY);
                if (i == 2 || i == 3)
                    PosicionesNaves.Add(PosicionNaveActualY);
                //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Numero de elementos en el array: %d"), PosicionesNaves.Num()));

            }
        };return;
    }
    else if (formacion == 2)
    {
        for (int i = 0; i < 6; i++) {
            FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 600.0f, ubicacionInicioNavesEnemigas.Z);

            for (int j = 0; j < 3; j++) {
                FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);
                if ((i == 0 || i == 5) && (j == 1 || j == 2))
                    PosicionesNaves.Add(PosicionNaveActualY);
                if ((i == 1 || i == 4) && j == 0)
                    PosicionesNaves.Add(PosicionNaveActualY);
                if (i == 2 || i == 3)
                    PosicionesNaves.Add(PosicionNaveActualY);
            }
        };return;
    }
    else if (formacion == 3)
    {
        for (int i = 0; i < 7; i++) {
            FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 550.0f, ubicacionInicioNavesEnemigas.Z);

            for (int j = 0; j < 3; j++) {
                FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);
                if (i % 2 == 0 && j % 2 == 0)
                    PosicionesNaves.Add(PosicionNaveActualY);
                if (i % 2 != 0 && j % 2 != 0)
                    PosicionesNaves.Add(PosicionNaveActualY);
            }
        };return;
    }
}
