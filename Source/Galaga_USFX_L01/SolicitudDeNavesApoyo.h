// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SolicitudDeNaves.h"
#include "SolicitudDeNavesApoyo.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ASolicitudDeNavesApoyo : public ASolicitudDeNaves
{
	GENERATED_BODY()

public:
		//Prepara la nave enemiga de apoyo
		virtual ANaveEnemiga* CrearNaveEnemiga(FString NombreNave, FVector Poscision, FRotator Rotacion) override;
	
};
