// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveReabastecimientoEnergia.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveReabastecimientoEnergia : public ANaveEnemigaReabastecimiento
{
	GENERATED_BODY()

public:
	ANaveReabastecimientoEnergia();
	virtual void Mover(float DeltaTime) override; //Sobrescribir los metodos
	virtual void Escapar() override;
	void RecargarEnergia(); //Metodo propio

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
