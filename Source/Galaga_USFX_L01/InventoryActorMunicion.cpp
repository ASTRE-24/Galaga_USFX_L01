// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActorMunicion.h"


AInventoryActorMunicion::AInventoryActorMunicion()
{
    // Establece el valor predeterminado de la propiedad bCanEverTick en verdadero
	PrimaryActorTick.bCanEverTick = true;

	// Personaliza la apariencia de la subclase aqu�
	CustomizeAppearance();
}

void AInventoryActorMunicion::CustomizeAppearance()
{
    // Personaliza la apariencia de la subclase aqu�
    // Por ejemplo, cambia la malla est�tica y el material

    // Ejemplo: Cambiar la malla est�tica a un cilindro
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
    if (CylinderMeshAsset.Succeeded())
    {
        GetStaticMeshComponent()->SetStaticMesh(CylinderMeshAsset.Object);
    }

    // Ejemplo: Cambiar el material
    // Puedes cargar un material o configurar un material preexistente aqu�

    // No olvides llamar al m�todo de la clase base despu�s de hacer los cambios necesarios
   // Super::CustomizeAppearance();
}