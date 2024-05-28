// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estado.h"
#include "Vehiculo.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AVehiculo : public AActor
{
	GENERATED_BODY()
private:
	IEstado* Estado;
	IEstado* EstadoVehiculoAereo;
	IEstado* EstadoVehiculoTerrestre;
	IEstado* EstadoVehiculoEspacial;

	UStaticMeshComponent* MallaVehiculo;
	
public:	
	// Sets default values for this actor's properties
	AVehiculo();
	IEstado* GetEstado();
	IEstado* GetEstadoVehiculoAereo();
	IEstado* GetEstadoVehiculoTerrestre();
	IEstado* GetEstadoVehiculoEspacial();
	FString GetNombreEstado();
	void SetEstado(IEstado* NuevoEstado);
	void Manejar();
	void Volar();
	void Navegar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
