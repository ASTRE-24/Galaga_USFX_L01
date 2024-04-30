// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InterfaceNaveNodriza.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterfaceNaveNodriza : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_L01_API IInterfaceNaveNodriza
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void movimientoNaveNodriza(float DeltaTime) = 0;
	virtual void movimientoNavesEnemigas() = 0;
	virtual void tipoDeArma() = 0;
	virtual void tiposNavesEnemigas() = 0;
	virtual void retiroNaveNodriza(float DeltaTime) = 0;

};
