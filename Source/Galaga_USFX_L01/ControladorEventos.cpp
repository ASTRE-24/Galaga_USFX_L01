// Fill out your copyright notice in the Description page of Project Settings.


#include "ControladorEventos.h"
#include "EstrategiaEnemigoAgresivo.h"
#include "EstrategiaEnemigoPasivo.h"
#include "EstrategiaEnemigoMuyPeligroso.h"
#include "EstrategiaEnemigoViolento.h"
#include "NaveEnemiga.h"
#include "Galaga_USFX_L01Pawn.h"
#include "vehiculo.h"

// Sets default values
AControladorEventos::AControladorEventos()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AControladorEventos::BeginPlay()
{
	Super::BeginPlay();
	EstrategiaAgresiva = GetWorld()->SpawnActor<AEstrategiaEnemigoAgresivo>(AEstrategiaEnemigoAgresivo::StaticClass());
	EstrategiaPasiva = GetWorld()->SpawnActor<AEstrategiaEnemigoPasivo>(AEstrategiaEnemigoPasivo::StaticClass());
	EstrategiaMuyPeligroso = GetWorld()->SpawnActor<AEstrategiaEnemigoMuyPeligroso>(AEstrategiaEnemigoMuyPeligroso::StaticClass());
	EstrategiaViolenta = GetWorld()->SpawnActor<AEstrategiaEnemigoViolento>(AEstrategiaEnemigoViolento::StaticClass());
}

// Called every frame
void AControladorEventos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AControladorEventos::InicializarComponente(AActor* Componente)
{
	vehiculo = Cast<AVehiculo>(Componente);
	jugador = Cast<AGalaga_USFX_L01Pawn>(Componente);
	naveEnemiga = Cast<ANaveEnemiga>(Componente);
}

void AControladorEventos::Notificar(AActor* Emisor, const FString& evento)
{
	if (evento == "Inicial")
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Evento Inicial"));
		vehiculo->ControlarEstado("Aereo");
	}
	else if (evento == "RecargaEnemigo")
	{

	}
	else if (evento == "RecargaJugador")
	{

	}
	else if (evento == "Lluvia de Obstaculos")
	{

	}
	else if (evento == "Cambio de Estrategia")
	{
		naveEnemiga = Cast<ANaveEnemiga>(Emisor);
		if (naveEnemiga->GetEnergia() >= 100) {
			naveEnemiga->CambiarEstrategia(EstrategiaPasiva);
			naveEnemiga->EjecutarEstrategia();
		}
		else if (naveEnemiga->GetEnergia() <= 75 && naveEnemiga->GetEnergia()>50 )
		{
			naveEnemiga->CambiarEstrategia(EstrategiaAgresiva);
			naveEnemiga->EjecutarEstrategia();
		}
		else if (naveEnemiga->GetEnergia() <= 50 && naveEnemiga->GetEnergia() > 25)
		{
			naveEnemiga->CambiarEstrategia(EstrategiaViolenta);
			naveEnemiga->EjecutarEstrategia();
		}
		else if (naveEnemiga->GetEnergia() <= 25)
		{
			naveEnemiga->CambiarEstrategia(EstrategiaMuyPeligroso);
			naveEnemiga->EjecutarEstrategia();
		}
	}
}

