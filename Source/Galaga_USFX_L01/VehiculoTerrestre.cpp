// Fill out your copyright notice in the Description page of Project Settings.


#include "VehiculoTerrestre.h"
#include "Vehiculo.h"

// Sets default values
AVehiculoTerrestre::AVehiculoTerrestre()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVehiculoTerrestre::BeginPlay()
{
	Super::BeginPlay();
	//Inicializar variables para el movimiento en forma de cuadrado
	DireccionMovimiento = FVector(1.0f, 0.0f, 0.0f);
	DistanciaRecorrida = 0.0f;
	LongitudLadoCuadrado = 300.0f;
	VelocidadMovimiento = 100.0f;
}

// Called every frame
void AVehiculoTerrestre::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVehiculoTerrestre::Manejar(AVehiculo* myVehiculo)
{
	if (myVehiculo->GetActorLocation().Z >60.0f)
	{
		myVehiculo->SetActorLocation(FVector(myVehiculo->GetActorLocation().X, myVehiculo->GetActorLocation().Y, myVehiculo->GetActorLocation().Z-1));
		return;
	}
	// Actualiza la posición del vehículo
	FVector NuevaPosicion = myVehiculo->GetActorLocation() + (DireccionMovimiento * VelocidadMovimiento * GetWorld()->GetDeltaSeconds());
	myVehiculo->SetActorLocation(NuevaPosicion);

	DistanciaRecorrida += (DireccionMovimiento * VelocidadMovimiento * GetWorld()->GetDeltaSeconds()).Size();

	// Cambia de dirección cuando se alcanza la longitud del lado del cuadrado
	if (DistanciaRecorrida >= LongitudLadoCuadrado)
	{
		DistanciaRecorrida = 0.0f;
		// Cambia la dirección del movimiento en sentido horario
		if (DireccionMovimiento == FVector(1.0f, 0.0f, 0.0f))
		{
			DireccionMovimiento = FVector(0.0f, 1.0f, 0.0f); // Mueve hacia adelante en el eje Y
		}
		else if (DireccionMovimiento == FVector(0.0f, 1.0f, 0.0f))
		{
			DireccionMovimiento = FVector(-1.0f, 0.0f, 0.0f); // Mueve hacia atrás en el eje X
		}
		else if (DireccionMovimiento == FVector(-1.0f, 0.0f, 0.0f))
		{
			DireccionMovimiento = FVector(0.0f, -1.0f, 0.0f); // Mueve hacia atrás en el eje Y
		}
		else if (DireccionMovimiento == FVector(0.0f, -1.0f, 0.0f))
		{
			DireccionMovimiento = FVector(1.0f, 0.0f, 0.0f); // Mueve hacia adelante en el eje X
		}
	}
	myVehiculo->SetActorRotation(DireccionMovimiento.Rotation());
	if (myVehiculo->TiempoTranscurrido >= 10.0f)
	{
		myVehiculo->SetEstado(myVehiculo->GetEstadoVehiculoAereo());
		myVehiculo->TiempoTranscurrido = 0.0f;
	}
}

void AVehiculoTerrestre::Volar(AVehiculo* myVehiculo)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vehiculo terrestre no puede volar"));
	//myVehiculo->SetEstado(myVehiculo->GetEstadoVehiculoAereo());
}

void AVehiculoTerrestre::Navegar(AVehiculo* myVehiculo)
{

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vehiculo terrestre no puede navegar"));
}

FString AVehiculoTerrestre::NombreEstado()
{
	return "Vehiculo Terrestre";
}

void AVehiculoTerrestre::Disparar(AVehiculo* myVehiculo)
{
	myVehiculo->TipoDisparo = "Disparo Doble";
}

void AVehiculoTerrestre::SuministrarCapsulas(AVehiculo* myVehiculo)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No es posible suministrar capsulas"));
}
