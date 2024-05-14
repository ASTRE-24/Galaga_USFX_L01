// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoPared.h"

AObstaculoPared::AObstaculoPared()
{
    // Carga el StaticMesh
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim.Shape_Trim'"));

    // Crea el componente de malla estática
    UStaticMeshComponent* Obstaculo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Obstaculo"));
    RootComponent = Obstaculo;

    // Verifica si se encontró el StaticMesh
    if (ShipMesh.Succeeded())
    {
        // Asigna el StaticMesh al componente de malla estática
        Obstaculo->SetStaticMesh(ShipMesh.Object);

        // Modifica la escala del componente de malla estática
        Obstaculo->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f)); // Aquí se ajusta la escala
    }
}

void AObstaculoPared::BeginPlay()
{
	Super::BeginPlay();
}

void AObstaculoPared::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AObstaculoPared::movimientoObstaculo()
{
}

void AObstaculoPared::danioObstaculo()
{
}