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
    

    // Métodos para gestionar los puntajes
    void AddScore(float Score);
    float GetScore();

    // Métodos para gestionar las vidas
    void LoseLife();
    float GetLives() ;

    // Métodos para gestionar la barra de salud
    void SetHealth(float NewHealth);
    float GetHealth();

private:
    // Variables para puntajes, vidas y salud
    float Score;
    float Lives;
    float Health;
};
