// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Armas.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AArmas : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArmas();
	
	int MunicionInicial;
	int MunicionActual;
	int MunicionMaxima;
	bool bCanFire;
	float FireRate;
	int TipoDisparo;
	FVector GunOffset;
	FTimerHandle TimerHandle_ShotTimerExpired;
	// Sonido de disparo
	class USoundBase* FireSound;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void ArmasDisparoNormal(AActor* NaveDisparo);
	void ArmaDisparoDoble(AActor* NaveDisparo);
	void ArmaDisparoTriple(AActor* NaveDisparo);
	void ArmaDisparoTripleAbanico(AActor* NaveDisparo);
	void ShotTimerExpired();
	void SeguirNave(FVector posicion, FRotator rotacion);

};
