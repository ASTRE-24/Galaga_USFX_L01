// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Estado.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEstado : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_L01_API IEstado
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void Manejar(class AVehiculo* vehiculo) = 0;
	virtual void Volar(class AVehiculo* vehiculo) = 0;
	virtual void Navegar(class AVehiculo* vehiculo) = 0;
	virtual FString NombreEstado() = 0;
};
