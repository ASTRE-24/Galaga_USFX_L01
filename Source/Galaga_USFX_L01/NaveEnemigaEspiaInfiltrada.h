// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaEspiaInfiltrada.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaEspiaInfiltrada : public ANaveEnemigaEspia
{
	GENERATED_BODY()
private:

	float Timer; //Timer para el movimiento de la nave
	float TiempoTrascurrido; //Tiempo transcurrido para el movimiento de la nave

public:
	ANaveEnemigaEspiaInfiltrada();
	virtual void Mover(float DeltaTime) override; //Sobrescribir los metodos
	virtual void Atacar() override;
	virtual void Escapar() override;
	void CambiarDisfraz(); //Metodo propio
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
