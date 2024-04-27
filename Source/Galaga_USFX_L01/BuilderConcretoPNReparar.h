// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuilderPortaNave.h"
#include "BuilderConcretoPNReparar.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ABuilderConcretoPNReparar : public AActor, public IBuilderPortaNave
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderConcretoPNReparar();
	class APortaNave* Portanave;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void ConstruirMedicina() override;
	virtual void ConstruirArmas() override;
	virtual class APortaNave* GetPortaNave() override;
};
