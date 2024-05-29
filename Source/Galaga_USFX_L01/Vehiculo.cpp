// Fill out your copyright notice in the Description page of Project Settings.


#include "Vehiculo.h"
#include "VehiculoTerrestre.h"
#include "VehiculoAereo.h"
#include "VehiculoEspacial.h"
#include "ActorComponentDisparo.h"

// Sets default values
AVehiculo::AVehiculo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Carga el StaticMesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Mehes/Vehiculo/TankAbrams_Free.TankAbrams_Free'"));

	// Crea el componente de malla estática
	MallaVehiculo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaVehiculo"));
	RootComponent = MallaVehiculo;
	//MallaVehiculo->SetWorldScale3D(FVector(0.8f, 0.8f, 0.8)); // Escala del vehículo
	
	DisparoComponent = CreateDefaultSubobject<UActorComponentDisparo>(TEXT("DisparoComponent"));
	TipoDisparo = "";

	// Verifica si se encontró el StaticMesh
	if (ShipMesh.Succeeded())
	{
		// Asigna el StaticMesh al componente de malla estática
		MallaVehiculo->SetStaticMesh(ShipMesh.Object);

		// Modifica la escala del componente de malla estática
		MallaVehiculo->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f)); // Aquí se ajusta la escala
	}
	
	TiempoTranscurrido = 0.0f;
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
	TiempoTranscurrido += DeltaTime;
	ControlarEstado();
	if (TipoDisparo == "Disparo Doble")
	{
		DisparoComponent->ArmaDisparoDoble();
	}
	else if (TipoDisparo == "Disparo Triple")
	{
		DisparoComponent->ArmaDisparoTriple();
	}
	else if (TipoDisparo == "Disparo Triple Abanico")
	{
		DisparoComponent->ArmaDisparoTripleAbanico();
	}
}

void AVehiculo::ControlarEstado()
{
	
}

void AVehiculo::SetEstado(IEstado* NuevoEstado)
{
	Estado = NuevoEstado;
	if (Estado == EstadoVehiculoTerrestre)
	{
		UStaticMesh* NewMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Mehes/Vehiculo/TankAbrams_Free.TankAbrams_Free'"));
		MallaVehiculo->SetStaticMesh(NewMesh);
	}
	else if (Estado == EstadoVehiculoAereo)
	{
		UStaticMesh* NewMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Mehes/Vehiculo/ju-87_body_ju_87.ju-87_body_ju_87'"));
		MallaVehiculo->SetStaticMesh(NewMesh);
	}
	else if (Estado == EstadoVehiculoEspacial)
	{
		UStaticMesh* NewMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Mehes/Vehiculo/Sample_Ship.Sample_Ship'"));
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

void AVehiculo::SuministrarCapsulas()
{
	Estado->SuministrarCapsulas(this);
}

void AVehiculo::Disparar()
{
	Estado->Disparar(this);
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
