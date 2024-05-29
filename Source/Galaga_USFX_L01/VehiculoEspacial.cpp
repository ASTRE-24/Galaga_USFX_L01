// Fill out your copyright notice in the Description page of Project Settings.


#include "VehiculoEspacial.h"
#include "Vehiculo.h"
#include "EnemigoCapsula.h"

// Sets default values
AVehiculoEspacial::AVehiculoEspacial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVehiculoEspacial::BeginPlay()
{
	Super::BeginPlay();
	// Inicializa variables para el movimiento circular
	inventarioFactory = GetWorld()->SpawnActor<IInventarioAFactory>(AEnemigoCapsula::StaticClass());
	Radio = 1000.0f; // Radio del círculo
	Angulo = 0.0f;
	VelocidadAngular = FMath::DegreesToRadians(30.0f); // Velocidad angular en radianes por segundo (ejemplo: 30 grados por segundo)
	Centro = FVector(0.0f, 0.0f, 301.0f); // Centro del círculo
}

// Called every frame
void AVehiculoEspacial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVehiculoEspacial::Manejar(AVehiculo* myVehiculo)
{
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vehiculo espacial no se puede conducir en tierra"));
}

void AVehiculoEspacial::Volar(AVehiculo* myVehiculo)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vehiculo espacial no puede volar en el espacio"));
}

void AVehiculoEspacial::Navegar(AVehiculo* myVehiculo)
{
	if (myVehiculo->GetActorLocation().Z <= 300.0f)
	{
		myVehiculo->SetActorLocation(FVector(myVehiculo->GetActorLocation().X, myVehiculo->GetActorLocation().Y, myVehiculo->GetActorLocation().Z + 1));
		return;
	}
	// Actualiza el ángulo
	Angulo += VelocidadAngular * GetWorld()->GetDeltaSeconds();
	if (Angulo > 2 * PI)
	{
		Angulo -= 2 * PI; // Mantener el ángulo entre 0 y 2?
	}

	// Calcula la nueva posición usando coordenadas polares
	float X = Centro.X + Radio * FMath::Cos(Angulo);
	float Y = Centro.Y + Radio * FMath::Sin(Angulo);
	float Z = Centro.Z; // Mantener el mismo nivel si no quieres movimiento vertical

	FVector NuevaPosicion = FVector(X, Y, Z);
	myVehiculo->SetActorLocation(NuevaPosicion);

	// Calcula la dirección del movimiento tangencial
	FVector Tangente = FVector(-FMath::Sin(Angulo), FMath::Cos(Angulo), 0.0f).GetSafeNormal();
	myVehiculo->SetActorRotation(Tangente.Rotation());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vehiculo espacial navegando"));
}

void AVehiculoEspacial::Disparar(AVehiculo* myVehiculo)
{
	myVehiculo->TipoDisparo = "Disparo Triple Abanico";
}

void AVehiculoEspacial::SuministrarCapsulas(AVehiculo* myVehiculo)
{
	int RandomNumber = FMath::FRandRange(0, 3);
	if (RandomNumber == 0)
	{
		inventarioFactory->crearCapsulaArma(myVehiculo->GetActorLocation());
	}
	else if (RandomNumber == 1)
	{
		inventarioFactory->crearCapsulaEnergia(myVehiculo->GetActorLocation());
	}
	else if (RandomNumber == 2)
	{
		inventarioFactory->crearCapsulaMunicion(myVehiculo->GetActorLocation());
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("ENEMIGOS PERRO"));
}

FString AVehiculoEspacial::NombreEstado()
{
	return "Vehiculo Espacial";
}

