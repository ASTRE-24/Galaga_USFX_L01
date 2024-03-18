// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaNodrizaBlindada.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaNodrizaBlindada : public ANaveEnemigaNodriza
{
	GENERATED_BODY()
public:
	ANaveEnemigaNodrizaBlindada();
	virtual void Mover(float DeltaTime) override; //Sobrescribir los metodos
	void ActivarEscudo(); //Metodo propio
};
