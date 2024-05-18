// Fill out your copyright notice in the Description page of Project Settings.


#include "MovimientoVertical.h"

// Sets default values for this component's properties
UMovimientoVertical::UMovimientoVertical()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	MovementRadius = 5;
	// ...
}


// Called when the game starts
void UMovimientoVertical::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMovimientoVertical::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
}

void UMovimientoVertical::MoveVertical(float DeltaTime)
{
	AActor* Parent = GetOwner();
	if (Parent)
	{
		if (Parent->GetActorLocation().Z >= 215.f)
		{

			// Find a new position for the object to go to
			auto NewPos = Parent->GetActorLocation() + FVector(0, 0, -1);
			Parent->SetActorLocation(NewPos);
		}
	}
}

