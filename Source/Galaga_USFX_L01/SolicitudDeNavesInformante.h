// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SolicitudDeNaves.h"
#include "SolicitudDeNavesInformante.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ASolicitudDeNavesInformante : public ASolicitudDeNaves
{
	GENERATED_BODY()
public:

	//Prepara la nave enemiga de informante
	virtual ANaveEnemiga* CrearNaveEnemiga(FString NombreNave, FVector Posicion, FRotator Rotacion) override;
};
