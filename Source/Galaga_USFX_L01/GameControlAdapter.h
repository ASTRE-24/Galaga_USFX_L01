// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ControlLogisticaJuego.h"
#include "LogisticaJuego.h"
#include "GameControlAdapter.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API UGameControlAdapter : public UObject, public IControlLogisticaJuego
{
	GENERATED_BODY()

public: 
    // Constructor y destructor
    UGameControlAdapter();
    virtual ~UGameControlAdapter();

    // Implementación de los métodos de la interfaz IScoreRecorder
    virtual void RecordScore(int32 Score) override;
    virtual int32 GetScore() const override;
    virtual void LoseLife() override;
    virtual int32 GetLives() const override;
    virtual void SetHealth(float NewHealth) override;
    virtual float GetHealth() const override;

    // Setter para ExternalGameControllerInstance
    void SetLogisticaJuego(ULogisticaJuego* Controller);

private:
    // Variable para almacenar una referencia a la clase externa del controlador de juego
    UPROPERTY()
    ULogisticaJuego* ClaseExternaInstance;
};
