// Fill out your copyright notice in the Description page of Project Settings.


#include "VehiculoAereo.h"
#include "Vehiculo.h"
#include "JugadorCapsula.h"

// Sets default values
AVehiculoAereo::AVehiculoAereo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVehiculoAereo::BeginPlay()
{
	Super::BeginPlay();
	// Inicializa variables para el movimiento en forma triangular
	VerticesTriangulo.Add(FVector(0.0f, 0.0f, 0.0f)); // Vértice 1
	VerticesTriangulo.Add(FVector(1000.0f, 0.0f, 0.0f)); // Vértice 2
	VerticesTriangulo.Add(FVector(500.0f, 866.0f, 0.0f)); // Vértice 3 (aproximadamente altura de un triángulo equilátero)
	inventarioFactory = GetWorld()->SpawnActor<IInventarioAFactory>(AJugadorCapsula::StaticClass());
	VerticeActual = 0;
	DireccionMovimiento = (VerticesTriangulo[1] - VerticesTriangulo[0]).GetSafeNormal();
	DistanciaRecorrida = 0.0f;
	VelocidadMovimiento = 200.0f; // Velocidad del movimiento del vehículo
}

// Called every frame
void AVehiculoAereo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVehiculoAereo::Manejar(AVehiculo* myVehiculo)
{
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vehiculo aereo no se puede conducir en tierra"));
}

void AVehiculoAereo::Volar(AVehiculo* myVehiculo)
{
	if (myVehiculo->GetActorLocation().Z <= 215.0f)
	{
		myVehiculo->SetActorLocation(FVector(myVehiculo->GetActorLocation().X, myVehiculo->GetActorLocation().Y, myVehiculo->GetActorLocation().Z+1));
		return;
	}
	FVector NuevaPosicion = myVehiculo->GetActorLocation() + (DireccionMovimiento * VelocidadMovimiento * GetWorld()->GetDeltaSeconds());
	myVehiculo->SetActorLocation(NuevaPosicion);

	DistanciaRecorrida += (DireccionMovimiento * VelocidadMovimiento * GetWorld()->GetDeltaSeconds()).Size();

	// Cambia de dirección cuando se alcanza la distancia al siguiente vértice
	if (DistanciaRecorrida >= (VerticesTriangulo[(VerticeActual + 1) % 3] - VerticesTriangulo[VerticeActual]).Size())
	{
		DistanciaRecorrida = 0.0f;
		VerticeActual = (VerticeActual + 1) % 3;
		DireccionMovimiento = (VerticesTriangulo[(VerticeActual + 1) % 3] - VerticesTriangulo[VerticeActual]).GetSafeNormal();
	}
	myVehiculo->SetActorRotation(DireccionMovimiento.Rotation());
	if (myVehiculo->TiempoTranscurrido >= 10.0f)
	{
		myVehiculo->SetEstado(myVehiculo->GetEstadoVehiculoEspacial());
		myVehiculo->TiempoTranscurrido = 0.0f;
	}
}

void AVehiculoAereo::Navegar(AVehiculo* myVehiculo)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vehiculo arereo no se puede navegar por espacio"));
	//myVehiculo->SetEstado(myVehiculo->GetEstadoVehiculoEspacial());
}

void AVehiculoAereo::Disparar(AVehiculo* myVehiculo)
{
	myVehiculo->TipoDisparo = "Disparo Triple";
}

void AVehiculoAereo::SuministrarCapsulas(AVehiculo* myVehiculo)
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
}

FString AVehiculoAereo::NombreEstado()
{
	return "Vehiculo Aereo";
}


