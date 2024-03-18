// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaEspiaTactica.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaEspiaTactica : public ANaveEnemigaEspia
{
	GENERATED_BODY()
	
public:
	ANaveEnemigaEspiaTactica();
	virtual void Mover(float DeltaTime) override; //Sobrescribir los metodos
	virtual void Atacar() override;
	void RecopilarInformacion(); //Metodo propio

};
