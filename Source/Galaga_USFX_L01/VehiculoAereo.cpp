// Fill out your copyright notice in the Description page of Project Settings.


#include "VehiculoAereo.h"
#include "Vehiculo.h"

// Sets default values
AVehiculoAereo::AVehiculoAereo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVehiculoAereo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVehiculoAereo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVehiculoAereo::Manejar(AVehiculo* myVehiculo)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vehiculo aereo manejando"));
}

void AVehiculoAereo::Volar(AVehiculo* myVehiculo)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vehiculo aereo volando"));
}

void AVehiculoAereo::Navegar(AVehiculo* myVehiculo)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Cambiando el vehiculo a modo espacial"));
	myVehiculo->SetEstado(myVehiculo->GetEstadoVehiculoEspacial());
}

FString AVehiculoAereo::NombreEstado()
{
	return "Vehiculo Aereo";
}


