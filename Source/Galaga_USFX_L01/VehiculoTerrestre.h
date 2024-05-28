// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estado.h"
#include "VehiculoTerrestre.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AVehiculoTerrestre : public AActor, public IEstado
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVehiculoTerrestre();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Manejar(class AVehiculo* myVehiculo) override;
	virtual void Volar(class AVehiculo* myVehiculo) override;
	virtual void Navegar(class AVehiculo* myVehiculo) override;
	virtual FString NombreEstado() override;
};
