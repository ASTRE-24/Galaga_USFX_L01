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
	ciclos = 0;
}

void AObstaculoPared::BeginPlay()
{
	Super::BeginPlay();
}

void AObstaculoPared::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bMoverse)
	if (ciclos < 4)
	{

		movimientoObstaculo(DeltaTime);
	}
	else Destroy();
}

void AObstaculoPared::movimientoObstaculo(float DeltaTime)
{
	posicion = GetActorLocation();
	float NewX = posicion.X - velocidad * DeltaTime;
	SetActorLocation(FVector(NewX, posicion.Y, posicion.Z));
	if (GetActorLocation().X <= -1800.0f)
	{

		SetActorLocation(FVector(1050.0f, posicion.Y, posicion.Z));
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

float AObstaculoPared::danioObstaculo()
{
	damage = 5;
	return damage;
}