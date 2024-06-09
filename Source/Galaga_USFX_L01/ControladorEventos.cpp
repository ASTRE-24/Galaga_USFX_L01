// Fill out your copyright notice in the Description page of Project Settings.


#include "ControladorEventos.h"
#include "EstrategiaEnemigoAgresivo.h"
#include "EstrategiaEnemigoPasivo.h"
#include "EstrategiaEnemigoMuyPeligroso.h"
#include "EstrategiaEnemigoViolento.h"
#include "NaveEnemiga.h"
#include "Galaga_USFX_L01Pawn.h"
#include "vehiculo.h"
#include "SpawnFacade.h"

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


void AControladorEventos::SetSpawnFacade(ASpawnFacade* SpawnFacade)
{
	Facade = SpawnFacade;
}

void AControladorEventos::SetNaveEnemiga(ANaveEnemiga* nave)
{
	naveEnemiga = nave;
}

void AControladorEventos::SetVehiculo(AVehiculo* vehiculoNeutral)
{
	vehiculo = vehiculoNeutral;
}

void AControladorEventos::SetJugador(AGalaga_USFX_L01Pawn* myjugador)
{
	jugador = myjugador;
}

void AControladorEventos::Notificar(AActor* Emisor, const FString& evento)
{
	if (evento == "RecargaJugador")
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Evento Inicial"));
		vehiculo->ControlarEstado("Aereo");
		jugador->ReturnToInitialPosition();
	}
	else if (evento == "RecargaEnemigo")
	{
		vehiculo->ControlarEstado("Espacial");
		Facade -> invocarCapsula();
		jugador->SetMaxProyectilesDisparados(jugador->GetMaxProyectilesDisparados() + 20);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Turquoise, TEXT("Bonus Disparo Rafaga +20 Municion"));
		jugador->SetTipoArma("Rafaga");
	}
	else if (evento == "LluviaObstaculos")
	{
		vehiculo->ControlarEstado("Terrestre");
		Facade->invocarObstaculos();
	}
	else if (evento == "Cambio de Estrategia")
	{
		naveEnemiga = Cast<ANaveEnemiga>(Emisor);
		if (naveEnemiga->GetEnergia() >= 100) 
		{
			naveEnemiga->CambiarEstrategia(EstrategiaPasiva);
			naveEnemiga->EjecutarEstrategia();
			if(jugador)
			jugador->FireRate = 0.2f;
		}
		else if (naveEnemiga->GetEnergia() <= 75 && naveEnemiga->GetEnergia()>50 )
		{
			naveEnemiga->CambiarEstrategia(EstrategiaAgresiva);
			naveEnemiga->EjecutarEstrategia();
			if (jugador)
			jugador->FireRate = 0.15f;
		}
		else if (naveEnemiga->GetEnergia() <= 50 && naveEnemiga->GetEnergia() > 25)
		{
			naveEnemiga->CambiarEstrategia(EstrategiaViolenta);
			naveEnemiga->EjecutarEstrategia();
			if (jugador)
			jugador->FireRate = 0.1f;
		}
		else if (naveEnemiga->GetEnergia() <= 25)
		{
			naveEnemiga->CambiarEstrategia(EstrategiaMuyPeligroso);
			naveEnemiga->EjecutarEstrategia();
			if (jugador)
			jugador->FireRate = 0.05f;
		}
	}
}

