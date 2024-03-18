// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaTransporteFurtivo.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaTransporteFurtivo : public ANaveEnemigaTransporte
{
	GENERATED_BODY()
	
public:
	ANaveEnemigaTransporteFurtivo();
	virtual void Destruirse() override; //Otra forma de destruirse
	void evitarRadares();
	virtual void Mover(float DeltaTime) override; //Otra forma de Moverse
};
