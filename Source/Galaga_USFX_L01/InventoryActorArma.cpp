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
}

