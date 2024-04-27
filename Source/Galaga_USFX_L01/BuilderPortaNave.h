// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BuilderPortaNave.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBuilderPortaNave : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_L01_API IBuilderPortaNave
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
        virtual void ConstruirMedicina() = 0;
        virtual void ConstruirArmas() = 0;
		virtual class APortaNave* GetPortaNave() = 0;

};