// Fill out your copyright notice in the Description page of Project Settings.


#include "VehiculoTerrestre.h"
#include "Vehiculo.h"

// Sets default values
AVehiculoTerrestre::AVehiculoTerrestre()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVehiculoTerrestre::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVehiculoTerrestre::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVehiculoTerrestre::Manejar(AVehiculo* myVehiculo)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vehiculo terrestre manejando"));
}

void AVehiculoTerrestre::Volar(AVehiculo* myVehiculo)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Cambiando Vehiculo a Modo Aereo"));
	myVehiculo->SetEstado(myVehiculo->GetEstadoVehiculoAereo());
}

void AVehiculoTerrestre::Navegar(AVehiculo* myVehiculo)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vehiculo terrestre no puede navegar"));
}

FString AVehiculoTerrestre::NombreEstado()
{
	return "Vehiculo Terrestre";
}
