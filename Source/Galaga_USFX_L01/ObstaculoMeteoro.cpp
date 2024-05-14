// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoMeteoro.h"

AObstaculoMeteoro::AObstaculoMeteoro()
{
    // Carga el StaticMesh
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

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

void AObstaculoMeteoro::BeginPlay()
{
	Super::BeginPlay();
}

void AObstaculoMeteoro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AObstaculoMeteoro::movimientoObstaculo()
{

}

void AObstaculoMeteoro::danioObstaculo()
{
	
}