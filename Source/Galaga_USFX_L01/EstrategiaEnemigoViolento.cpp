// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaEnemigoViolento.h"
#include "NaveEnemiga.h"

// Sets default values
AEstrategiaEnemigoViolento::AEstrategiaEnemigoViolento()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaEnemigoViolento::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaEnemigoViolento::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaEnemigoViolento::MoverseYDisparar(ANaveEnemiga* Nave)
{
	Nave->SetMovimiento(false);
	Nave->SetMoverse(true);
    Nave->SetTipoArma("TripleAbanico");
}


