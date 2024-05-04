// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorComponentDisparo.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_L01_API UActorComponentDisparo : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorComponentDisparo();

	//Dispara un proyectil
    void ArmasDisparoNormal();
    void ArmaDisparoDoble();
    void ArmaDisparoTriple();
    void ArmaDisparoTripleAbanico();
    void StartFireTimer();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    // Timer para controlar la velocidad de disparo
    FTimerHandle TimerHandle_ShotTimerExpired;

    // 
    FTimerHandle TimerHandle_FireTimer;

    // Controla si es posible disparar
    bool bCanFire;

    // Función para el temporizador de disparo expirado
    void ShotTimerExpired();

    // Velocidad de disparo (tiempo entre disparos)
    float FireRate;

    // Offset para la posición de generación del proyectil
    FVector GunOffset;

    // Sonido de disparo
    class USoundBase* FireSound;
		
};
