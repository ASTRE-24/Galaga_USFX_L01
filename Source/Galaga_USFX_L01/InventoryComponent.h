// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryActor.h"
#include "Containers/Queue.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_L01_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	//UPROPERTY()
	TQueue<AInventoryActor*> CurrentInventory; // Cola de objetos en el inventario
	//TArray<AInventoryActor*> CurrentInventory;

	UFUNCTION()
	int32 AddToInventory(AInventoryActor* ActorToAdd);	

	UFUNCTION()
	void RemoveFromInventory(AInventoryActor* ActorToRemove); 

	// Funcion para el movimiento de los objetos en el inventario
	UFUNCTION()
	void MoveInventoryItem();

	UPROPERTY()
	float MovementRadius; // Radio de movimiento de los objetos en el inventario

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
