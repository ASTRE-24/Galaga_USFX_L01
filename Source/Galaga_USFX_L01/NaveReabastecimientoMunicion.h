// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveReabastecimientoMunicion.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveReabastecimientoMunicion : public ANaveEnemigaReabastecimiento
{
	GENERATED_BODY()
	
public:
	ANaveReabastecimientoMunicion();
	virtual void Mover(float DeltaTime) override; //Sobrescribir los metodos
	void RecargarMunicion(); //Metodo propio

	virtual void Tick(float DeltaTime) override; //Sobrescribir el metodo tick
};
