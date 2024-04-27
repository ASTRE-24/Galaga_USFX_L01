// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorPortaNave.h"

// Sets default values
ADirectorPortaNave::ADirectorPortaNave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirectorPortaNave::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirectorPortaNave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirectorPortaNave::ConstruirPortaNave()
{
	BuilderPortaNave->ConstruirMedicina();
	BuilderPortaNave->ConstruirArmas();
}

void ADirectorPortaNave::SetBuilderPortaNave(AActor* Builder)
{
	BuilderPortaNave = Cast<IBuilderPortaNave>(Builder);
}

APortaNave* ADirectorPortaNave::GetPortaNave()
{
	return BuilderPortaNave->GetPortaNave();
}

