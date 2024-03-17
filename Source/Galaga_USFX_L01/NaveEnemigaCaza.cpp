// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

	Timer = 0.0f; //Inicializa el timer en 0

}

void ANaveEnemigaCaza::Mover(float DeltaTime)
{
	// Obtiene la posición actual del actor
	FVector PosicionActual = GetActorLocation();

	Timer += DeltaTime; //Aumenta el timer con el tiempo transcurrido

	//Movimiento sinusoidal
	float Amplitud = 10.0f;
	float Frecuencia = 4.0f;

	float NewX = PosicionActual.X + Amplitud * FMath::Sin(Frecuencia * Timer);
	float NewY = PosicionActual.Y;
	float NewZ = PosicionActual.Z;

	// Crea un nuevo vector de posición con las coordenadas aleatorias y la misma Z que la posición actual
	//FVector NuevaPosicion = FVector(PosicionActual.X + NewX, PosicionActual.Y + NewY, PosicionActual.Z);

	// Establece la nueva posición del actor
	SetActorLocation(FVector(NewX,NewY,NewZ));
}

void ANaveEnemigaCaza::Disparar()
{
}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaCaza::Destruirse()
{

}

void ANaveEnemigaCaza::Escapar()
{

}

void ANaveEnemigaCaza::Atacar()
{

}
