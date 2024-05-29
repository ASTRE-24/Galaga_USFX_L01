// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SuscriberEstrategia.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USuscriberEstrategia : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_L01_API ISuscriberEstrategia
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void ActualizarEstrategia() = 0;
};
