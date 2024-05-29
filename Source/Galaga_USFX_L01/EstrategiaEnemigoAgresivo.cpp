// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaEnemigoAgresivo.h"
#include "NaveEnemiga.h"

// Sets default values
AEstrategiaEnemigoAgresivo::AEstrategiaEnemigoAgresivo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaEnemigoAgresivo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaEnemigoAgresivo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaEnemigoAgresivo::MoverseYDisparar(ANaveEnemiga* Nave)
{
	Nave->SetMovimiento(true);
	Nave->SetMoverse(false);
	Nave->SetTipoMovimiento("Arco");
    Nave->SetTipoArma("Doble");
}

