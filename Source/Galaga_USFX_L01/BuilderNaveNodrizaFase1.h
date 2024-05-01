// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfaceBuilderNaveNodriza.h"
#include "NaveEnemigaNodriza.h"
#include "BuilderNaveNodrizaFase1.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ABuilderNaveNodrizaFase1 : public AActor, public IInterfaceBuilderNaveNodriza
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderNaveNodrizaFase1();
	ANaveEnemigaNodriza* naveNodriza;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void construirMovimientoNaveNodriza() override;
	virtual void construirMovimientoNavesEnemigas() override;
	virtual void construirTipoDeArma() override;
	virtual void construirTiposNavesEnemigas() override;
	virtual class ANaveEnemigaNodriza* getNaveNodriza() override;
};
