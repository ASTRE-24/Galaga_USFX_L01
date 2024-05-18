// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventarioAFactory.h"
#include "InterfaceCapsulaEnemiga.h"
#include "EnemigoCapsula.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AEnemigoCapsula : public AActor, public IInventarioAFactory
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemigoCapsula();
	bool Move = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual AActor* crearCapsulaArma(FVector posicion) override;
	virtual AActor* crearCapsulaEnergia(FVector posicion) override;
	virtual AActor* crearCapsulaMunicion(FVector posicion) override;
};
