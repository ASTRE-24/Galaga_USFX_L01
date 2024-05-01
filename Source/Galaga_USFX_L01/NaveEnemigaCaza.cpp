// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"
#include "ActorComponentDisparo.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Mehes/CajaSalud/MK6_OBJ.MK6_OBJ'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	mallaNaveEnemiga->SetWorldScale3D(FVector(0.7f, 0.8f, 1.0f));
	
	Timer = 0.0f; //Inicializa el timer en 0
	TiempoParaDetenerse = 5.0f; //Inicializa el tiempo para detenerse en 5 segundos
	TiempoParaReanudar = 2.0f; //Tiempo para reanudar el movimiento
	// Inicializar el componente de disparo
	
	// Asignar valores necesarios (como FireRate, GunOffset, etc.) al componente de disparo si es necesario
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("NaveEnemigaCaza Constructor"));
}

void ANaveEnemigaCaza::Mover(float DeltaTime)
{
	//if (bShouldMove) {

		// Obtiene la posici�n actual del actor
		FVector PosicionActual = GetActorLocation();

		Timer += DeltaTime; //Aumenta el timer con el tiempo transcurrido

		//Movimiento sinusoidal
		float Amplitud = 5.0f;
		float Frecuencia = 4.0f;
		float Velocidad = 300.0f;

		float NewX = PosicionActual.X - Velocidad*DeltaTime;
		float NewY = PosicionActual.Y- Amplitud * FMath::Sin(Frecuencia * Timer);//Es negativa para que se mueva hacia abajo;
		float NewZ = PosicionActual.Z;


		// Establece la nueva posici�n del actor
		SetActorLocation(FVector(NewX, NewY, NewZ));

		if (GetActorLocation().X <= -1800.0f)
		{

			SetActorLocation(FVector(1850.0f, NewY, NewZ));

			
		}
		if (GetActorLocation().Y >= 1850)
		{
			SetActorLocation(FVector(NewX, -1850.0f, PosicionActual.Z));
		}

		if (GetActorLocation().Y <= -1850)
		{
			SetActorLocation(FVector(NewX, 1850.0f, PosicionActual.Z));
		}

}



void ANaveEnemigaCaza::Disparar()
{
	

}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bMoverse)
	{
		Mover(DeltaTime);
	}
	
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

void ANaveEnemigaCaza::BeginPlay()
{
	Super::BeginPlay();

	
}
