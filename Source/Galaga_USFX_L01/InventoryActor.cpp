// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActor.h"

#include "Engine/CollisionProfile.h"

void AInventoryActor::PickUp()
{
	SetActorTickEnabled(false); 
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void AInventoryActor::PutDown(FTransform TargetLocation)
{
	SetActorTickEnabled(true);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorLocation(TargetLocation.GetLocation());
}

AInventoryActor::AInventoryActor():Super()
{
	PrimaryActorTick.bCanEverTick = true;
	auto MeshAsset =
		ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
			if (MeshAsset.Object != nullptr)
			{
				GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
				GetStaticMeshComponent()->SetCollisionProfileName(
					UCollisionProfile::Pawn_ProfileName);
			}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	SetActorEnableCollision(true);

}

void AInventoryActor::BeginPlay()
{
	Super::BeginPlay();
	CustomizeAppearance(); // Llama a la función de personalización al comienzo del juego
	//SetLifeSpan(10.0f); // Destruye el objeto después de 10 segundos
}

void AInventoryActor::CustomizeAppearance()
{
	// No hace nada en la clase base, las clases hijas pueden sobrescribir esta función
}