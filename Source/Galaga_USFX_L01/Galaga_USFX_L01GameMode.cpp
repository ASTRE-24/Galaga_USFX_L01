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
    FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

    UWorld* const World = GetWorld();
    if (World != nullptr)
    {
        for (int i = 0; i < 6; i++) {
            //Esto es para crear las naves enemigas en una ubicacion especifica para comenzar
            FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 600.0f, ubicacionInicioNavesEnemigas.Z);
            
            for (int j = 0; j < 5; j++) {
                FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);
                //PosicionesNavesEnemigas.Add(j, PosicionNaveActualY);//Agrega la posicion de la nave al TMap
                ANaveEnemiga* NaveEnemigaTemporal = nullptr; // Crear un puntero a nave enemiga

                // Generar un número aleatorio entre 0 y 1
                float RandomNumber = FMath::FRandRange(0.0f, 1.0f);

                // Probabilidad de generar una nave caza o transporte (50% cada una)
                if (RandomNumber <= 0.5f) {
                    NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaTransporteLogistico>(PosicionNaveActualY, rotacionNave); // Spawn nave caza
                }
                else {
                    NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaTransporteFurtivo>(PosicionNaveActualY, rotacionNave); // Spawn nave transporte
                }

                if (NaveEnemigaTemporal != nullptr) {
                    NaveEnemigas.Add(GetUniqueNameForNave(), NaveEnemigaTemporal); // Agregar nave al TMap
                }
            }
        }
        TiempoTranscurrido = 0;
    }
}

FString AGalaga_USFX_L01GameMode::GetUniqueNameForNave()
{
    static int32 Counter = 0;
    return FString::Printf(TEXT("NaveEnemiga_%d"), Counter++);
}


