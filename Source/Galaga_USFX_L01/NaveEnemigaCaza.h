// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.generated.h"

/**
 *
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaCaza : public ANaveEnemiga
{
	GENERATED_BODY()
private:
	int cantidadBombas;
	float Timer; //Timer para el movimiento de la nave
    float bShouldMove;// Variable para controlar el movimiento de la nave
	float TiempoParaDetenerse; //Tiempo para detenerse
	float TiempoParaReanudar; //Tiempo para reanudar
	// Nuevo temporizador para reanudar el movimiento
	FTimerHandle TimerHandle_ReanudarMovimiento;
	

public:
	ANaveEnemigaCaza(); //Constructor
	FORCEINLINE int GetCantidadBombas() const { return cantidadBombas; }
	FORCEINLINE void SetCantidadBombas(int _cantidadBombas) { cantidadBombas = _cantidadBombas; }
protected:
	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	void ReanudarMovimiento();
	virtual void Destruirse();
	virtual void Escapar();
	virtual void Atacar();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};