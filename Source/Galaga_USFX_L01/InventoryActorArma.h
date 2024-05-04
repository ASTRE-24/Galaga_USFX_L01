// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryActor.h"
#include "InventoryActorArma.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API AInventoryActorArma : public AInventoryActor
{
	GENERATED_BODY()
public:
	AInventoryActorArma();
	virtual void NotifyHit(class UPrimitiveComponent*
		MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
		bool bSelfMoved, FVector HitLocation, FVector HitNormal,
		FVector NormalImpulse, const FHitResult& Hit) override;
};
