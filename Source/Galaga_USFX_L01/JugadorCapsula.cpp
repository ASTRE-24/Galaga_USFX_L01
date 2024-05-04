// Fill out your copyright notice in the Description page of Project Settings.


#include "JugadorCapsula.h"

// Sets default values
AJugadorCapsula::AJugadorCapsula()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJugadorCapsula::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJugadorCapsula::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

