// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovimientoVertical.h"
#include "InventoryActor.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API AInventoryActor : public AStaticMeshActor
{
	GENERATED_BODY()



public:
	AInventoryActor();
	bool bMoverse = true;
	virtual void PickUp(); //Función para recoger el objeto
	virtual void PutDown(FTransform TargetLocation); //Función para dejar el objeto
	virtual void CustomizeAppearance();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	// Componente de movimiento vertical
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movimiento")
	UMovimientoVertical* MovementComponent;

	
};
