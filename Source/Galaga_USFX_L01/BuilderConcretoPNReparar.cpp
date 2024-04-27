// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderConcretoPNReparar.h"
#include "PortaNave.h"

// Sets default values
ABuilderConcretoPNReparar::ABuilderConcretoPNReparar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuilderConcretoPNReparar::BeginPlay()
{
	Super::BeginPlay();
	Portanave = GetWorld()->SpawnActor<APortaNave>(APortaNave::StaticClass());
}

// Called every frame
void ABuilderConcretoPNReparar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderConcretoPNReparar::ConstruirMedicina()
{
	UE_LOG(LogTemp, Warning, TEXT("Construyendo medicina"));
}

void ABuilderConcretoPNReparar::ConstruirArmas()
{
	UE_LOG(LogTemp, Warning, TEXT("Construyendo armas"));
}

class APortaNave* ABuilderConcretoPNReparar::GetPortaNave()
{
	return Portanave;
}

