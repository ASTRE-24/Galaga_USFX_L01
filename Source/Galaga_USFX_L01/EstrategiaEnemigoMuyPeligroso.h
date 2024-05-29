// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BatallaEstrategy.h"
#include "EstrategiaEnemigoMuyPeligroso.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AEstrategiaEnemigoMuyPeligroso : public AActor, public IBatallaEstrategy
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategiaEnemigoMuyPeligroso();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void MoverseYDisparar(class ANaveEnemiga* Nave) override;
	

};
