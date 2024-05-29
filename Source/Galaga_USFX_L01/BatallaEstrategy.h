// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BatallaEstrategy.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBatallaEstrategy : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_L01_API IBatallaEstrategy
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void MoverseYDisparar(class ANaveEnemiga* Nave) = 0;
	
};
