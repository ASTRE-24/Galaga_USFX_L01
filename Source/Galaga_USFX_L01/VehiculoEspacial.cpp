// Fill out your copyright notice in the Description page of Project Settings.


#include "VehiculoEspacial.h"
#include "Vehiculo.h"

// Sets default values
AVehiculoEspacial::AVehiculoEspacial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVehiculoEspacial::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVehiculoEspacial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVehiculoEspacial::Manejar(AVehiculo* myVehiculo)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vehiculo espacial manejando"));
}

void AVehiculoEspacial::Volar(AVehiculo* myVehiculo)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vehiculo espacial volando"));
}

void AVehiculoEspacial::Navegar(AVehiculo* myVehiculo)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vehiculo espacial navegando"));
}

FString AVehiculoEspacial::NombreEstado()
{
	return "Vehiculo Espacial";
}

