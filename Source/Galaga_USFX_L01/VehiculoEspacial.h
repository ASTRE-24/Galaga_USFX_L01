// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estado.h"
#include "VehiculoEspacial.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AVehiculoEspacial : public AActor, public IEstado
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVehiculoEspacial();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Manejar(AVehiculo* myVehiculo) override;
	virtual void Volar(AVehiculo* myVehiculo) override;
	virtual void Navegar(AVehiculo* myVehiculo) override;
	virtual FString NombreEstado() override;
};
