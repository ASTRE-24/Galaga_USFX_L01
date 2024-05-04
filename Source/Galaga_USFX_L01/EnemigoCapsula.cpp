// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoCapsula.h"
#include "CapsulaEnemigaArma.h"
#include "CapsulaEnemigaEnergia.h"
#include "CapsulaEnemigaMunicion.h"

// Sets default values
AEnemigoCapsula::AEnemigoCapsula()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemigoCapsula::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemigoCapsula::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AActor* AEnemigoCapsula::crearCapsulaArma(FVector posicion)
{
	return GetWorld()->SpawnActor<ACapsulaEnemigaArma>(ACapsulaEnemigaArma::StaticClass(), posicion, FRotator (0,0,0));
}

AActor* AEnemigoCapsula::crearCapsulaEnergia(FVector posicion)
{
	return GetWorld()->SpawnActor<ACapsulaEnemigaEnergia>(ACapsulaEnemigaEnergia::StaticClass(), posicion, FRotator(0, 0, 0));
}

AActor* AEnemigoCapsula::crearCapsulaMunicion(FVector posicion)
{
	return GetWorld()->SpawnActor<ACapsulaEnemigaMunicion>(ACapsulaEnemigaMunicion::StaticClass(), posicion, FRotator(0, 0, 0));
}

