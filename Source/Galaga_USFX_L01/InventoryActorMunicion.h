// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryActor.h"
#include "InventoryActorMunicion.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API AInventoryActorMunicion : public AInventoryActor
{
	GENERATED_BODY()
	
public:
	AInventoryActorMunicion();
	virtual void CustomizeAppearance() override;
};
