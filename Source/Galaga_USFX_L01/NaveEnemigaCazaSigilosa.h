// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaCazaSigilosa.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaCazaSigilosa : public ANaveEnemigaCaza
{
	GENERATED_BODY()
private:
	float Timer; //Timer para el movimiento de la nave
	float TiempoTranscurrido; //Tiempo transcurrido
	
public:
	ANaveEnemigaCazaSigilosa();
	virtual void Mover(float Deltatime) override; //Sobrescribir los metodos
	virtual void Atacar() override;
	void Detectar(); //Metodo propio
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
