// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaCazaVeloz.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaCazaVeloz : public ANaveEnemigaCaza
{
	GENERATED_BODY()
public:
	ANaveEnemigaCazaVeloz();
	virtual void Mover(float DeltaTime) override; //Sobrescribir los metodos
	virtual void Escapar() override;
	virtual void Atacar() override;
	virtual void Destruirse() override;
};
