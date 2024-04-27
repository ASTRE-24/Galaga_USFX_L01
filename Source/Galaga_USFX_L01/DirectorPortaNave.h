// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuilderPortaNave.h"
#include "DirectorPortaNave.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ADirectorPortaNave : public AActor
{
	GENERATED_BODY()

private:
	IBuilderPortaNave* BuilderPortaNave;
	
public:	
	// Sets default values for this actor's properties
	ADirectorPortaNave();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Crear los builders
	void ConstruirPortaNave();
	void SetBuilderPortaNave(AActor* Builder);	
	class APortaNave* GetPortaNave();
};
