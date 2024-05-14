// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NaveEnemiga.h"
#include "SolicitudDeNavesApoyo.h"
#include "SolicitudDeNavesAtaque.h"
#include "SolicitudDeNavesInformante.h"
#include "InventarioAFactory.h"
#include "Obstaculo.h"
#include "InventoryActor.h"
#include "SpaunFacade.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ASpaunFacade : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASpaunFacade();
	ASolicitudDeNavesApoyo* navesApoyo;
	ASolicitudDeNavesAtaque* navesAtaque;
	ASolicitudDeNavesInformante* navesInformante;
	AObstaculo* obstaculo;
	IInventarioAFactory* inventarioFactory;

	TArray<ANaveEnemiga*> navesEnemigas;
	TArray<AObstaculo*> obstaculos;
	TArray<AInventoryActor*> inventarios;
	TArray<FVector> PosicionesNaves;

	//virtual void BeginPlay() override;
	void invocarNaves();
	void invocarObstaculos();
	void invocarCapsula();
	void posiciones();
	void realizaTareas();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
//void USpawnFacade::invocarNaves()
//{
//    navesApoyo = GetWorld()->SpawnActor<ASolicitudDeNavesApoyo>(ASolicitudDeNavesApoyo::StaticClass());
//    navesAtaque = GetWorld()->SpawnActor<ASolicitudDeNavesAtaque>(ASolicitudDeNavesAtaque::StaticClass());
//    navesInformante = GetWorld()->SpawnActor<ASolicitudDeNavesInformante>(ASolicitudDeNavesInformante::StaticClass());
//    //Aniadir los nombres al TArray
//    TArray<FString> NombresNavesAtaque;
//    TArray<FString> NombresNavesApoyo;
//    TArray<FString> NombresNavesInformante;
//    NombresNavesAtaque.Add("NaveEnemigaCaza");
//    NombresNavesAtaque.Add("NaveEnemigaCazaSigilosa");
//    NombresNavesAtaque.Add("NaveEnemigaCazaVeloz");
//    NombresNavesApoyo.Add("NaveEnemigaTransporte");
//    NombresNavesApoyo.Add("NaveEnemigaTransporteFurtivo");
//    NombresNavesApoyo.Add("NaveEnemigaTransporteLogistico");
//    NombresNavesInformante.Add("NaveEnemigaEspia");
//    NombresNavesInformante.Add("NaveEnemigaEspiaInfiltrada");
//    NombresNavesInformante.Add("NaveEnemigaEspiaTactica");
//    NombresNavesApoyo.Add("NaveEnemigaReabastecimiento");
//    NombresNavesApoyo.Add("NaveReabastecimientoEnergia");
//    NombresNavesApoyo.Add("NaveReabastecimientoMunicion");
//
//
//    UWorld* const World = GetWorld();
//    if (World != nullptr)
//    {
//        //Creacion de las naves enemigas
//
//        for (int i = 0; i < PosicionesNaves.Num(); i++) {
//            // Selecciona un tipo de nave aleatorio
//
//            int random = FMath::RandRange(0, 2);
//
//            if (random == 0)
//            {
//                int32 RandomIndex = FMath::RandRange(0, NombresNavesAtaque.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
//                ANaveEnemiga* NaveEnemigaAtaque = navesAtaque->OrdenarNaveEnemiga(NombresNavesAtaque[RandomIndex]);
//                navesEnemigas.Add(NaveEnemigaAtaque);
//            }
//            else if (random == 1)
//            {
//                int32 RandomIndex = FMath::RandRange(0, NombresNavesApoyo.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
//                // Spawnea la nave aleatoria
//                ANaveEnemiga* NaveEnemigaApoyo = navesApoyo->OrdenarNaveEnemiga(NombresNavesApoyo[RandomIndex]);
//                navesEnemigas.Add(NaveEnemigaApoyo);
//            }
//            else
//            {
//                int32 RandomIndex = FMath::RandRange(0, NombresNavesInformante.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
//                // Spawnea la nave aleatoria
//                ANaveEnemiga* NaveEnemigaInformante = navesInformante->OrdenarNaveEnemiga(NombresNavesInformante[RandomIndex]);
//                navesEnemigas.Add(NaveEnemigaInformante);
//            }
//        }
//    }
//
//}
//
//void USpawnFacade::invocarObstaculos()
//{
//}
//
//void USpawnFacade::invocarCapsula()
//{
//}
//
//void USpawnFacade::realizaTareas()
//{
//}
//
//void USpawnFacade::posiciones()
//{
//    int formacion = FMath::RandRange(1, 3); //Genera un numero aleatorio entre 1 y 3
//    FVector ubicacionInicioNavesEnemigas = FVector(1850.0f, -1540.7f, 216.0f);
//    if (formacion == 1)
//    {
//        for (int i = 0; i < 6; i++) {
//            FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 600.0f, ubicacionInicioNavesEnemigas.Z);
//
//            for (int j = 0; j < 3; j++) {
//                FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);
//                if ((i == 0 || i == 5) && j == 0)
//                    PosicionesNaves.Add(PosicionNaveActualY);
//                if ((i == 1 || i == 4) && (j == 0 || j == 1))
//                    PosicionesNaves.Add(PosicionNaveActualY);
//                if (i == 2 || i == 3)
//                    PosicionesNaves.Add(PosicionNaveActualY);
//                //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Numero de elementos en el array: %d"), PosicionesNaves.Num()));
//
//            }
//        };return;
//    }
//    else if (formacion == 2)
//    {
//        for (int i = 0; i < 6; i++) {
//            FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 600.0f, ubicacionInicioNavesEnemigas.Z);
//
//            for (int j = 0; j < 3; j++) {
//                FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);
//                if ((i == 0 || i == 5) && (j == 1 || j == 2))
//                    PosicionesNaves.Add(PosicionNaveActualY);
//                if ((i == 1 || i == 4) && j == 0)
//                    PosicionesNaves.Add(PosicionNaveActualY);
//                if (i == 2 || i == 3)
//                    PosicionesNaves.Add(PosicionNaveActualY);
//            }
//        };return;
//    }
//    else if (formacion == 3)
//    {
//        for (int i = 0; i < 7; i++) {
//            FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 550.0f, ubicacionInicioNavesEnemigas.Z);
//
//            for (int j = 0; j < 3; j++) {
//                FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);
//                if (i % 2 == 0 && j % 2 == 0)
//                    PosicionesNaves.Add(PosicionNaveActualY);
//                if (i % 2 != 0 && j % 2 != 0)
//                    PosicionesNaves.Add(PosicionNaveActualY);
//            }
//        };return;
//    }
//}
