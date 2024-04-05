// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorSpawnerComponent.h"
#include "Escudo.h"


// Sets default values for this component's properties
UActorSpawnerComponent::UActorSpawnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
    

	// ...
}


// Called when the game starts
void UActorSpawnerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
    

}


// Called every frame
void UActorSpawnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UActorSpawnerComponent::SpawnEscudo()
{
    // Get the owner Pawn
    APawn* OwnerPawn = Cast<APawn>(GetOwner());
    if (OwnerPawn)
    {
        // Get the owner Pawn's location and rotation
        FVector PawnLocation = OwnerPawn->GetActorLocation();
        FRotator PawnRotation = OwnerPawn->GetActorRotation();

        // Calculate the spawn location in front of the owner Pawn
        float SpawnDistance = 100.0f; // Distance in front of the Pawn
        FVector SpawnLocation = PawnLocation + PawnRotation.Vector() * SpawnDistance;

        // Spawn the Escudo object
        UWorld* World = GetWorld();
        if (World)
        {
            ActorToSpawn = World->SpawnActor<AEscudo>( SpawnLocation, PawnRotation);
            if (ActorToSpawn)
            {
                // Set the lifespan of the Escudo object to 5 seconds
                //NewEscudo->SetLifeSpan(5.0f);
                FTimerHandle Timer;
                World->GetTimerManager().SetTimer(Timer, this,
                    &UActorSpawnerComponent::DestroyEscudo, 5);
            }
        }
    }
}

void UActorSpawnerComponent::DestroyEscudo()
{
    if (ActorToSpawn != nullptr)
    {
        // Displays a red message on the screen for 10 seconds
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,
            TEXT("Escudo destruido"));
        ActorToSpawn->Destroy();
    }
}
