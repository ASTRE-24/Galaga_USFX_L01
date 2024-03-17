// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporte.h"

ANaveEnemigaTransporte::ANaveEnemigaTransporte()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	Timer = 0.0f; //Inicializa el timer en 0
}

void ANaveEnemigaTransporte::Mover(float DeltaTime)
{
	// Obtiene la posici�n actual del actor
	FVector PosicionActual = GetActorLocation();

	//Aumenta el Timer con el tiempo transcurrido
	Timer += DeltaTime;

	// Parametros del movimiento sinusoidal
	float Amplitud = 10.0f;
	float Frecuencia = 4.0f;

	//Calcula las nuevas coordenadas de la elipse
	float X = -Amplitud * FMath::Sin(Frecuencia * Timer);
	

	//Establece la nueva posición del actor sumando las coordenadas a la posición actual
	SetActorLocation(PosicionActual + FVector(X, 0.0f, 0.0f)); //Otra forma de hacer que se mueva
	
}

void ANaveEnemigaTransporte::Disparar()
{
}

void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

