// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaEnemigoPasivo.h"
#include "NaveEnemiga.h"

// Sets default values
AEstrategiaEnemigoPasivo::AEstrategiaEnemigoPasivo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaEnemigoPasivo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaEnemigoPasivo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaEnemigoPasivo::MoverseYDisparar(ANaveEnemiga* Nave)
{
	Nave->SetMovimiento(true);
	Nave->SetMoverse(false);
	Nave->SetTipoMovimiento("ZigZag");
    Nave->SetTipoArma("Normal");
}



