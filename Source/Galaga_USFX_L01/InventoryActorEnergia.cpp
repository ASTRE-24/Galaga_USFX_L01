// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActorEnergia.h"

AInventoryActorEnergia::AInventoryActorEnergia()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> 
        CylinderMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Mehes/CajaSalud/First_Aid_Kit_Caja01.First_Aid_Kit_Caja01'"));
    if (CylinderMeshAsset.Succeeded())
    {
        GetStaticMeshComponent()->SetStaticMesh(CylinderMeshAsset.Object);
    }
}

