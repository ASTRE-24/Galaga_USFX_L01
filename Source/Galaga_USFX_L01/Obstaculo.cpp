// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstaculo.h"
#include "Galaga_USFX_L01Pawn.h"

// Sets default values
AObstaculo::AObstaculo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    movimiento = false;
    distanciaObs = 0;
}

// Called when the game starts or when spawned
void AObstaculo::BeginPlay()
{
	Super::BeginPlay();
    
}

// Called every frame
void AObstaculo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    /*if (movimiento) {
        movimientoObstaculo();
    }*/
   

}

//void AObstaculo::movimientoObstaculo()
//{
//	// Encuentra el objeto del jugador
//	AGalaga_USFX_L01Pawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn<AGalaga_USFX_L01Pawn>();
//
//	// Verifica si se encontró al jugador
//    if (PlayerPawn)
//    {
//		// Calcula la dirección hacia el jugador
//		FVector DirectionToPlayer = PlayerPawn->GetActorLocation() - GetActorLocation();
//		DirectionToPlayer.Normalize();
//
//		// Calcula la nueva posición para el obstáculo
//		FVector NewPosition = PlayerPawn->GetActorLocation() - (DirectionToPlayer * (200+distanciaObs)); // 100 es la distancia constante
//
//		// Mueve el obstáculo hacia la nueva posición
//		SetActorLocation(NewPosition);
//	}
//}   

