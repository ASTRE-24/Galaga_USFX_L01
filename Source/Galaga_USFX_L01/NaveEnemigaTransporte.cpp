// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporte.h"
#include "Galaga_USFX_L01GameMode.h"

ANaveEnemigaTransporte::ANaveEnemigaTransporte()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Mehes/NavesEnemigas/Spaceships_2.Spaceships_2'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	mallaNaveEnemiga->SetWorldScale3D(FVector(0.6f, 1.0f, 1.0f));
	
	//Asiganar el indice de fila en el Constructor
	
	//PosicionInicial = GetActorLocation();
}


void ANaveEnemigaTransporte::Mover(float DeltaTime)
{
	// Obtiene la posición actual del actor
	FVector PosicionActual = GetActorLocation();
	Timer = 0.0f; //Inicializa el timer en 0
	
	

	Timer += DeltaTime; //Aumenta el timer con el tiempo transcurrido
	float Velocidad = 5.0f;
	//Movimiento sinusoidal
	/*float Amplitud = 10.0f;
	float Frecuencia = 4.0f;*/

	float NewX = PosicionActual.X - Velocidad;
	float NewY = PosicionActual.Y;
	float NewZ = PosicionActual.Z;

	// Crea un nuevo vector de posición con las coordenadas aleatorias y la misma Z que la posición actual
	//FVector NuevaPosicion = FVector(PosicionActual.X + NewX, PosicionActual.Y + NewY, PosicionActual.Z);

	// Establece la nueva posición del actor
	SetActorLocation(FVector(NewX, NewY, NewZ));

	//hacer que la nave llegue a una ubicacion especifica e inicie donde su posicioninicial
	

	if (GetActorLocation().X<=-1800.0f)
	{
		
		SetActorLocation(FVector(1800.0f, NewY, NewZ));
		
		Timer = 0.0f;
	}

	////Si la nave llega a destino, reaparecer en la posicion inicial
	//if (FVector::Distance(PosicionActual, Destino) < 5.0f)
	//{
	//	SetActorLocation(PosicionInicial);//Reaparece en la posicion inicial
	//	Timer = 0.0f;//Reinicia el timer
	//}
}

void ANaveEnemigaTransporte::Disparar()
{
}

void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bMoverse)
	{
		Mover(DeltaTime);
	}
	
}

void ANaveEnemigaTransporte::Destruirse()
{

}

void ANaveEnemigaTransporte::Escapar()
{

}

void ANaveEnemigaTransporte::Atacar()
{

}

