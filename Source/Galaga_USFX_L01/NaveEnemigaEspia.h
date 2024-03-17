// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaEspia.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaEspia : public ANaveEnemiga
{
	GENERATED_BODY()
	
private:
	float duracionInvisibilidad;
	FString tipoCamuflaje;

public:
	ANaveEnemigaEspia();

	FORCEINLINE float GetDuracionInvisibilidad() const { return duracionInvisibilidad; }
	FORCEINLINE FString GetTipoCamuflaje() const { return tipoCamuflaje; }

	FORCEINLINE void SetResistencia(float _duracionInvisibilidad) { duracionInvisibilidad = _duracionInvisibilidad; }
	FORCEINLINE void SetNombre(FString _tipoCamuflaje) { tipoCamuflaje = _tipoCamuflaje; }

protected:
	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	virtual void Destruirse();
	virtual void Escapar();
	virtual void Atacar();
};

