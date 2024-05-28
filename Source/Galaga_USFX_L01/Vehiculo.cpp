// Fill out your copyright notice in the Description page of Project Settings.


#include "Vehiculo.h"
#include "VehiculoTerrestre.h"
#include "VehiculoAereo.h"
#include "VehiculoEspacial.h"

// Sets default values
AVehiculo::AVehiculo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Carga el StaticMesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));

	// Crea el componente de malla estática
	MallaVehiculo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaVehiculo"));
	RootComponent = MallaVehiculo;

	// Verifica si se encontró el StaticMesh
	if (ShipMesh.Succeeded())
	{
		// Asigna el StaticMesh al componente de malla estática
		MallaVehiculo->SetStaticMesh(ShipMesh.Object);

		// Modifica la escala del componente de malla estática
		MallaVehiculo->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f)); // Aquí se ajusta la escala
	}
	

}

// Called when the game starts or when spawned
void AVehiculo::BeginPlay()
{
	Super::BeginPlay();

	EstadoVehiculoTerrestre = GetWorld()->SpawnActor<AVehiculoTerrestre>();
	EstadoVehiculoAereo = GetWorld()->SpawnActor<AVehiculoAereo>();
	EstadoVehiculoEspacial = GetWorld()->SpawnActor<AVehiculoEspacial>();
	Estado = EstadoVehiculoTerrestre;
}

// Called every frame
void AVehiculo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVehiculo::SetEstado(IEstado* NuevoEstado)
{
	Estado = NuevoEstado;
	if (Estado == EstadoVehiculoTerrestre)
	{
		UStaticMesh* NewMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
		MallaVehiculo->SetStaticMesh(NewMesh);
	}
	else if (Estado == EstadoVehiculoAereo)
	{
		UStaticMesh* NewMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
		MallaVehiculo->SetStaticMesh(NewMesh);
	}
	else if (Estado == EstadoVehiculoEspacial)
	{
		UStaticMesh* NewMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
		MallaVehiculo->SetStaticMesh(NewMesh);
	}
}

void AVehiculo::Manejar()
{
	Estado->Manejar(this);
}

void AVehiculo::Volar()
{
	Estado->Volar(this);
}

void AVehiculo::Navegar()
{
	Estado->Navegar(this);
}

IEstado* AVehiculo::GetEstado()
{
	return Estado;
}

IEstado* AVehiculo::GetEstadoVehiculoAereo()
{
	return EstadoVehiculoAereo;
}

IEstado* AVehiculo::GetEstadoVehiculoTerrestre()
{
	return EstadoVehiculoTerrestre;
}

IEstado* AVehiculo::GetEstadoVehiculoEspacial()
{
	return EstadoVehiculoEspacial;
}

FString AVehiculo::GetNombreEstado()
{
	return "Estoy en un  " + Estado->NombreEstado();	
}
