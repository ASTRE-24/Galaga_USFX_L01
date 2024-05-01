// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InterfaceBuilderNaveNodriza.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterfaceBuilderNaveNodriza : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_L01_API IInterfaceBuilderNaveNodriza
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void construirMovimientoNaveNodriza() = 0;
	virtual void construirFormacionNavesEnemigas() = 0;
	virtual void construirTipoDeArma() = 0;
	virtual void construirTiposNavesEnemigas() = 0;
	virtual class ANaveEnemigaNodriza* getNaveNodriza() = 0;
};
