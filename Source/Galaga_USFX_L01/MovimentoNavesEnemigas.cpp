// Fill out your copyright notice in the Description page of Project Settings.


#include "MovimentoNavesEnemigas.h"

// Sets default values for this component's properties
UMovimentoNavesEnemigas::UMovimentoNavesEnemigas()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	MovementSpeed = 30.0f;
	MovementRange = 2.0f;
	ZigZagFrequency = 1.0f;
	TimeElapsed = 0.0f;
	ArcFrequency = 2.0f; // Ajusta según sea necesario
	ArcAmplitude = 3.0f; // Ajusta según sea necesario
	// ...
}


// Called when the game starts
void UMovimentoNavesEnemigas::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	//mostrar el mensaje del vector de la posicion inicial
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, InitialPosition.ToString());
}


// Called every frame
void UMovimentoNavesEnemigas::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// Inicializar la posición inicial
	
}

void UMovimentoNavesEnemigas::movimientoZigzag(float DeltaTime)
{

	InitialPosition = GetOwner()->GetActorLocation();
	// Increment the time elapsed
	TimeElapsed += DeltaTime;

	// Calculate the new position
	float MovementDelta = MovementSpeed * DeltaTime;
	FVector NewPosition = InitialPosition;

	NewPosition.Y += FMath::Sin(TimeElapsed * ZigZagFrequency) * MovementRange;
	//NewPosition.X += MovementDelta;

	// Set the new position of the actor
	GetOwner()->SetActorLocation(NewPosition);
}

void UMovimentoNavesEnemigas::movimientoLineal(float DeltaTime)
{
	// Obtener la posición inicial del actor
	InitialPosition = GetOwner()->GetActorLocation();

	// Incrementar el tiempo transcurrido
	TimeElapsed += DeltaTime;

	// Calcular el nuevo desplazamiento basado en la velocidad de movimiento
	float MovementDelta = MovementSpeed * DeltaTime;

	// Crear un nuevo vector de posición basado en la posición inicial
	FVector NewPosition = InitialPosition;

	// Ajustar la posición X para moverse de ida y vuelta
	NewPosition.X -= 5*FMath::Cos(TimeElapsed * ArcFrequency) * MovementDelta;

	// Ajustar la posición Y para moverse en arco
	NewPosition.Y += FMath::Sin(TimeElapsed * ArcFrequency) * ArcAmplitude;

	// Establecer la nueva posición del actor
	GetOwner()->SetActorLocation(NewPosition);
	// Incrementar el tiempo transcurrido
	
}

