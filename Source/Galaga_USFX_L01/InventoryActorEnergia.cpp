// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActorEnergia.h"

AInventoryActorEnergia::AInventoryActorEnergia()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> 
        CylinderMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube'"));
    if (CylinderMeshAsset.Succeeded())
    {
        GetStaticMeshComponent()->SetStaticMesh(CylinderMeshAsset.Object);
    }
}

