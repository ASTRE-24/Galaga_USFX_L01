// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estado.h"
#include "InventarioAFactory.h"
#include "VehiculoAereo.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AVehiculoAereo : public AActor, public IEstado
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVehiculoAereo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	TArray<FVector> VerticesTriangulo;
	IInventarioAFactory* inventarioFactory;
	int VerticeActual;
	FVector DireccionMovimiento;
	float DistanciaRecorrida;
	float VelocidadMovimiento;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Manejar(AVehiculo* myVehiculo) override;
	virtual void Volar(AVehiculo* myVehiculo) override;
	virtual void Navegar(AVehiculo* myVehiculo) override;
	virtual void Disparar(AVehiculo* myVehiculo) override;
	virtual void SuministrarCapsulas(AVehiculo* myVehiculo) override;
	virtual FString NombreEstado() override;
};
