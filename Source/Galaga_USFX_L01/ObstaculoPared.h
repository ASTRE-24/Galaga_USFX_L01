// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "ObstaculoPared.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API AObstaculoPared : public AObstaculo
{
	GENERATED_BODY()
	
public:
	AObstaculoPared();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void movimientoObstaculo(float DeltaTime) override;
	virtual float danioObstaculo() override;
};
