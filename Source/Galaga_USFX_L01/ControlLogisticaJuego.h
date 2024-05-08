// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ControlLogisticaJuego.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UControlLogisticaJuego : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_L01_API IControlLogisticaJuego
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
    // Método para registrar la puntuación
    virtual void RecordScore(int32 Score) = 0;

    // Método para obtener la puntuación
    virtual int32 GetScore() const = 0;

    // Método para perder una vida
    virtual void LoseLife() = 0;

    // Método para obtener la cantidad de vidas
    virtual int32 GetLives() const = 0;

    // Método para establecer la salud
    virtual void SetHealth(float NewHealth) = 0;

    // Método para obtener la salud
    virtual float GetHealth() const = 0;
};
