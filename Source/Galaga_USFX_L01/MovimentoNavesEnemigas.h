// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MovimentoNavesEnemigas.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_L01_API UMovimentoNavesEnemigas : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovimentoNavesEnemigas();
	float MovementSpeed;
	float MovementRange;
	float ZigZagFrequency;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	FVector InitialPosition;
	float TimeElapsed;
	float ArcFrequency;
	float ArcAmplitude;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void movimientoZigzag(float DeltaTime);
	void movimientoLineal(float DeltaTime);
	//void movimientoCircular(float DeltaTime);

		
};
