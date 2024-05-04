// Fill out your copyright notice in the Description page of Project Settings.


#include "JugadorCapsula.h"
#include "InventoryActorArma.h"
#include "InventoryActorEnergia.h"
#include "InventoryActorMunicion.h"

// Sets default values
AJugadorCapsula::AJugadorCapsula()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AJugadorCapsula::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJugadorCapsula::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AActor* AJugadorCapsula::crearCapsulaArma(FVector posicion)
{
	return GetWorld()->SpawnActor<AInventoryActorArma>(AInventoryActorArma::StaticClass(), posicion, FRotator(0, 0, 0));
}

AActor* AJugadorCapsula::crearCapsulaEnergia(FVector posicion)
{
	return GetWorld()->SpawnActor<AInventoryActorEnergia>(AInventoryActorEnergia::StaticClass(), posicion, FRotator(0, 0, 0));
}

AActor* AJugadorCapsula::crearCapsulaMunicion(FVector posicion)
{
	return GetWorld()->SpawnActor<AInventoryActorMunicion>(AInventoryActorMunicion::StaticClass(), posicion, FRotator(0, 0, 0));
}

