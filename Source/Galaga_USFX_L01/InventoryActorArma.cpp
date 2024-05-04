// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActorArma.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "Components/StaticMeshComponent.h"

AInventoryActorArma::AInventoryActorArma()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    static ConstructorHelpers::FObjectFinder<UStaticMesh>
        CylinderMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Mehes/CajaSalud/First_Aid_Kit_Caja01.First_Aid_Kit_Caja01'"));
    if (CylinderMeshAsset.Succeeded())
    {
        GetStaticMeshComponent()->SetStaticMesh(CylinderMeshAsset.Object);
    }
	GetStaticMeshComponent()->SetSimulatePhysics(true);
	GetStaticMeshComponent()->SetNotifyRigidBodyCollision(true);
}

void AInventoryActorArma::NotifyHit(class UPrimitiveComponent*
	MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal,
	FVector NormalImpulse, const FHitResult& Hit)
{

	ANaveEnemiga* NaveEnemiga = Cast<ANaveEnemiga>(Other);
	if (NaveEnemiga)
	{
		Destroy();
	}
	else return;
}