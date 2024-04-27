// Fill out your copyright notice in the Description page of Project Settings.


#include "PortaNave.h"

// Sets default values
APortaNave::APortaNave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APortaNave::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APortaNave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APortaNave::caracteristicas()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("PortaNave"));
}

