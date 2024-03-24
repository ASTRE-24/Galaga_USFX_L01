// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActorMunicion.h"


AInventoryActorMunicion::AInventoryActorMunicion()
{
    // Establece el valor predeterminado de la propiedad bCanEverTick en verdadero
	PrimaryActorTick.bCanEverTick = true;

	// Personaliza la apariencia de la subclase aquí
	CustomizeAppearance();
}

void AInventoryActorMunicion::CustomizeAppearance()
{
    // Personaliza la apariencia de la subclase aquí
    // Por ejemplo, cambia la malla estática y el material

    // Ejemplo: Cambiar la malla estática a un cilindro
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
    if (CylinderMeshAsset.Succeeded())
    {
        GetStaticMeshComponent()->SetStaticMesh(CylinderMeshAsset.Object);
    }

    // Ejemplo: Cambiar el material
    // Puedes cargar un material o configurar un material preexistente aquí

    // No olvides llamar al método de la clase base después de hacer los cambios necesarios
   // Super::CustomizeAppearance();
}