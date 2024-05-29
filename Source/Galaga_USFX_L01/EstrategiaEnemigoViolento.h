// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BatallaEstrategy.h"
#include "EstrategiaEnemigoViolento.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AEstrategiaEnemigoViolento : public AActor, public IBatallaEstrategy
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategiaEnemigoViolento();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Ejecutamos el movimiento de la nave
	virtual void MoverseYDisparar(class ANaveEnemiga* Nave) override;
	
};
