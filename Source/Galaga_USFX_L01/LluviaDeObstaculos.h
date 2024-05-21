// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Notificador.h"
#include "LluviaDeObstaculos.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ALluviaDeObstaculos : public ANotificador
{
	GENERATED_BODY()
public:
	float TimeObstaculo;
	ALluviaDeObstaculos();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	void IniciarLluvia();
	void SetTimeObstaculo(float NewTimeObstaculo);
};
