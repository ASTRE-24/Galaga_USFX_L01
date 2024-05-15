// Fill out your copyright notice in the Description page of Project Settings.


#include "MovimentoNavesEnemigas.h"

// Sets default values for this component's properties
UMovimentoNavesEnemigas::UMovimentoNavesEnemigas()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	MovementSpeed = 30.0f;
	MovementRange = 2.0f;
	ZigZagFrequency = 1.0f;
	TimeElapsed = 0.0f;
	// ...
}


// Called when the game starts
void UMovimentoNavesEnemigas::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	//mostrar el mensaje del vector de la posicion inicial
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, InitialPosition.ToString());
}


// Called every frame
void UMovimentoNavesEnemigas::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	/*float NewX = InitialPosition.X - MovementSpeed * DeltaTime;
	GetOwner()->SetActorLocation(FVector(NewX, InitialPosition.Y, InitialPosition.Z+216));*/
	// Increment the time elapsed
	//TimeElapsed += DeltaTime;

	//// Calculate the new position
	//float MovementDelta = MovementSpeed * DeltaTime;
	//FVector NewPosition = InitialPosition + FVector(0,0,215);

	//NewPosition.Y += FMath::Sin(TimeElapsed * ZigZagFrequency) * MovementRange;
	//NewPosition.X += MovementDelta;

	//// Set the new position of the actor
	//GetOwner()->SetActorLocation(NewPosition);
}

void UMovimentoNavesEnemigas::movimientoZigzag(float DeltaTime)
{

	InitialPosition = GetOwner()->GetActorLocation();
	// Increment the time elapsed
	TimeElapsed += DeltaTime;

	// Calculate the new position
	float MovementDelta = MovementSpeed * DeltaTime;
	FVector NewPosition = InitialPosition;

	NewPosition.Y += FMath::Sin(TimeElapsed * ZigZagFrequency) * MovementRange;
	//NewPosition.X += MovementDelta;

	// Set the new position of the actor
	GetOwner()->SetActorLocation(NewPosition);
}

