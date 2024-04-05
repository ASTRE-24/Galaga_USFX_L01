// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ActorSpawnerComponent.generated.h"


class AEscudo;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_L01_API UActorSpawnerComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorSpawnerComponent();
	//Generará un actor cuando se lo llame
	
	UFUNCTION(BlueprintCallable, Category = Cookbook)
	void SpawnEscudo();
	UPROPERTY(EditAnywhere)
	AEscudo* ActorToSpawn;

	void DestroyEscudo();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
