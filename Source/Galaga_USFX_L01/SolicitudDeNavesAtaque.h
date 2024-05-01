// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SolicitudDeNaves.h"
#include "SolicitudDeNavesAtaque.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ASolicitudDeNavesAtaque : public ASolicitudDeNaves
{
	GENERATED_BODY()
public:
		//Prepara la nave enemiga de ataque
		virtual ANaveEnemiga* CrearNaveEnemiga(FString NombreNave) override;
	
};
