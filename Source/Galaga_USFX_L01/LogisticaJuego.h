// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LogisticaJuego.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ULogisticaJuego : public UObject
{
	GENERATED_BODY()
public:
    // Constructor y destructor
    ULogisticaJuego();
    virtual ~ULogisticaJuego();

    // Métodos para gestionar los puntajes
    void AddScore(int32 Score);
    int32 GetScore() const;

    // Métodos para gestionar las vidas
    void LoseLife();
    int32 GetLives() const;

    // Métodos para gestionar la barra de salud
    void SetHealth(float NewHealth);
    float GetHealth() const;

private:
    // Variables para puntajes, vidas y salud
    int32 Score;
    int32 Lives;
    float Health;
};
