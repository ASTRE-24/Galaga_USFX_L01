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
private:

	float Timer; //Timer para el movimiento de la nave
	float TiempoTranscurrido; //Tiempo transcurrido
public:
	ANaveEnemigaCazaVeloz();
	virtual void Mover(float DeltaTime) override; //Sobrescribir los metodos
	virtual void Escapar() override;
	virtual void Atacar() override;
	virtual void Destruirse() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
