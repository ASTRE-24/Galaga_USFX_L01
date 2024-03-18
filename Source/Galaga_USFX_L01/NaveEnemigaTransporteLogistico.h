// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaTransporteLogistico.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaTransporteLogistico : public ANaveEnemigaTransporte
{
	GENERATED_BODY()
	
public:
	ANaveEnemigaTransporteLogistico();
	virtual void Mover(float DeltaTime) override; //Sobrescribir los metodos
	virtual void Escapar() override;
	virtual void Atacar() override;
	virtual void Destruirse() override;
	void entregarSuministros();// metodo propio
};
