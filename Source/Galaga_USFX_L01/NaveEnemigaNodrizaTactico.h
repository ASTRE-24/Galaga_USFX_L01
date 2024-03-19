// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaNodrizaTactico.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaNodrizaTactico : public ANaveEnemigaNodriza
{
	GENERATED_BODY()
	
public:
	ANaveEnemigaNodrizaTactico();
	virtual void Mover(float DeltaTime) override; //Sobrescribir los metodos
	void DesplegarTropas(); //Metodo propio
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
