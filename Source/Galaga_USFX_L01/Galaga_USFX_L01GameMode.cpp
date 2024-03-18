// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01GameMode.h"
#include "Galaga_USFX_L01Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaCaza.h"

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
	FVector ubicacionInicioNavesEnemigas = FVector(1850.0f, -1585.7f, 250.0f);
	FVector ubicacionInicioNavesEnemigasTransporte = FVector(500.0f, 500.0f, 250.0f);


	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);
	

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		for (int i = 0; i < 6; i++) {
			//Esto es para crear las naves enemigas en una ubicacion especifica para comenzar
			
			FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 528.5f, ubicacionInicioNavesEnemigas.Z);
			
			for (int j = 0 ; j < 5; j++) {
				FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y , PosicionNaveActualX.Z);

			if (i % 2 == 0) {

				ANaveEnemigaCaza* NaveEnemigaCazaTemporal = World->SpawnActor<ANaveEnemigaCaza>(PosicionNaveActualY, rotacionNave);// Se crea el objeto de la nave enemiga
				TANavesEnemigas.Push(NaveEnemigaCazaTemporal); //Agrega la nave al array de todas sus clases hijas de NaveEnemiga
			}
			else {
				ANaveEnemigaTransporte* NaveEnemigaTransporteTemporal = World->SpawnActor<ANaveEnemigaTransporte>(PosicionNaveActualY, rotacionNave);
				TANavesEnemigas.Push(NaveEnemigaTransporteTemporal);
			}
		    }
			//ANaveEnemigaCaza* NaveEnemigaCazaTemporal = World->SpawnActor<ANaveEnemigaCaza>(PosicionNaveActual, rotacionNave);// Se crea el objeto de la nave enemiga

			
			//TANavesEnemigas.Push(NaveEnemigaCazaTemporal); //Agrega la nave al array de todas sus clases hijas de NaveEnemiga
		}

		/*float nuevaposicionX = ubicacionInicioNavesEnemigasTransporte.X - 300.0f;

		for (int j = 0; j < 5; j++) {
			FVector PosicionNaveActual = FVector(nuevaposicionX, ubicacionInicioNavesEnemigasTransporte.Y + j * 300, ubicacionInicioNavesEnemigasTransporte.Z);
			ANaveEnemigaTransporte* NaveEnemigaTransporteTemporal = World->SpawnActor<ANaveEnemigaTransporte>(PosicionNaveActual, rotacionNave);

			
			TANavesEnemigas.Push(NaveEnemigaTransporteTemporal);
		}*/

		//Esto era para probar que se crearan las naves enemigas en un ubicaion especifica
		//NaveEnemigaTransporte01 = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionNave01, rotacionNave);
		//NaveEnemigaCaza01 = World->SpawnActor<ANaveEnemigaCaza>(ubicacionNave02, rotacionNave); 

		TiempoTranscurrido = 0;
	}

	/*NaveEnemigaCaza01->SetPosicion(FVector(-500.0f, 500.0f, 200.0f));
	NaveEnemigaTransporte01->SetPosicion(FVector(500.0f, -500.0f, 200.0f));*/

}

//void AGalaga_USFX_L01GameMode::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//	TiempoTranscurrido++;
//
//	if (TiempoTranscurrido >= 100)
//	{
//		int numeroEnemigo = FMath::RandRange(0, 9);
//		if (GEngine)
//		{
//			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Hola estoy aqui")));
//
//
//			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Entero: %d"), numeroEnemigo));//Imprime el numero aleatorio
//			
//
//		}
//		//TANavesEnemigas[numeroEnemigo]->PrimaryActorTick.bCanEverTick = false;
//		TANavesEnemigas[numeroEnemigo]->SetVelocidad(0);
//	}
//}
