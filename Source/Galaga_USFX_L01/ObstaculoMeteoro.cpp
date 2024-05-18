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
	ciclos = 0;
}

void AObstaculoMeteoro::BeginPlay()
{
	Super::BeginPlay();
}

void AObstaculoMeteoro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bMoverse)
	if (ciclos < 4)
	{
		
		movimientoObstaculo(DeltaTime);
	}
	else Destroy();
}

void AObstaculoMeteoro::movimientoObstaculo(float Deltatime)
{
	posicion = GetActorLocation();
	float NewX = posicion.X - 1.5*velocidad*Deltatime;
	float NewY = posicion.Y + 0.5*velocidad * Deltatime;
	SetActorLocation(FVector(NewX, NewY, posicion.Z));
	if (GetActorLocation().X <= -1800.0f)
	{

		SetActorLocation(FVector(1050.0f, NewY, posicion.Z));
		ciclos++;

	}
	if (GetActorLocation().Y >= 1850)
	{
		SetActorLocation(FVector(NewX, -1850.0f, posicion.Z));
	}

	if (GetActorLocation().Y <= -1850)
	{
		SetActorLocation(FVector(NewX, 1850.0f, posicion.Z));
	}
}

float AObstaculoMeteoro::danioObstaculo()
{
	damage = 15;
	return damage;
}