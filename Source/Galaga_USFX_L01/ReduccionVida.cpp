// Fill out your copyright notice in the Description page of Project Settings.


#include "ReduccionVida.h"
#include "NaveEnemiga.h"
#include "SuscriberEstrategia.h"
#include "EstrategiaEnemigoAgresivo.h"
#include "EstrategiaEnemigoPasivo.h"
#include "EstrategiaEnemigoMuyPeligroso.h"
#include "EstrategiaEnemigoViolento.h"

AReduccionVida::AReduccionVida()
{
	PrimaryActorTick.bCanEverTick = true;
	flags = 0;
}

void AReduccionVida::BeginPlay()
{
	Super::BeginPlay();
	EstrategiaAgresiva = GetWorld()->SpawnActor<AEstrategiaEnemigoAgresivo>(AEstrategiaEnemigoAgresivo::StaticClass());
	EstrategiaPasiva = GetWorld()->SpawnActor<AEstrategiaEnemigoPasivo>(AEstrategiaEnemigoPasivo::StaticClass());
	EstrategiaMuyPeligroso = GetWorld()->SpawnActor<AEstrategiaEnemigoMuyPeligroso>(AEstrategiaEnemigoMuyPeligroso::StaticClass());
	EstrategiaViolenta = GetWorld()->SpawnActor<AEstrategiaEnemigoViolento>(AEstrategiaEnemigoViolento::StaticClass());
}

void AReduccionVida::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (flags == 0)
	{
		VidaPromedioNaveEnemiga();
		if (PromEnerNavEnemigas <= 200)
		{
			for (AActor* Objetivo : Objetivos)
			{
				ISuscriberEstrategia* Suscriptor = Cast<ISuscriberEstrategia>(Objetivo);
				if (Suscriptor)
				{
					ANaveEnemiga* Nave = Cast<ANaveEnemiga>(Objetivo);
					if (Nave)
					{
						Nave->CambiarEstrategia(EstrategiaPasiva);
						CambioDeEstrategia();
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Cambio de estrategia"));
					}

				}
			}
			flags = 1;
		}
	}
	else if (flags == 1)
	{
		VidaPromedioNaveEnemiga();
		if (PromEnerNavEnemigas <= 80)
		{
			for (AActor* Objetivo : Objetivos)
			{
				ISuscriberEstrategia* Suscriptor = Cast<ISuscriberEstrategia>(Objetivo);
				if (Suscriptor)
				{
					ANaveEnemiga* Nave = Cast<ANaveEnemiga>(Objetivo);
					if (Nave)
					{
						Nave->CambiarEstrategia(EstrategiaAgresiva);
						CambioDeEstrategia();
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Cambio de estrategia"));
					}

				}
			}
			flags = 2;
		}
	}
	else if (flags == 2)
	{
		VidaPromedioNaveEnemiga();
		if (PromEnerNavEnemigas <= 50)
		{
			for (AActor* Objetivo : Objetivos)
			{
				ISuscriberEstrategia* Suscriptor = Cast<ISuscriberEstrategia>(Objetivo);
				if (Suscriptor)
				{
					ANaveEnemiga* Nave = Cast<ANaveEnemiga>(Objetivo);
					if (Nave)
					{
						Nave->CambiarEstrategia(EstrategiaViolenta);
						CambioDeEstrategia();
					}

				}
			}
			flags = 3;
		}
	}
	else if (flags == 3)
	{
		VidaPromedioNaveEnemiga();
		if (PromEnerNavEnemigas <= 30)
		{
			for (AActor* Objetivo : Objetivos)
			{
				ISuscriberEstrategia* Suscriptor = Cast<ISuscriberEstrategia>(Objetivo);
				if (Suscriptor)
				{
					ANaveEnemiga* Nave = Cast<ANaveEnemiga>(Objetivo);
					if (Nave)
					{
						Nave->CambiarEstrategia(EstrategiaMuyPeligroso);
						CambioDeEstrategia();
					}

				}
			}
			flags = 4;
		}
	}

}

void AReduccionVida::CambioDeEstrategia()
{
	NotificarCambioEstrategia();
}

void AReduccionVida::SetTimeObstaculo(float NewTimeObstaculo)
{
	
}

void AReduccionVida::VidaPromedioNaveEnemiga()
{

	float EnergiaTotalNavesEnemigas = 0;
	for (AActor* Objetivo : Objetivos)
	{
		ISuscriberEstrategia* Suscriptor = Cast<ISuscriberEstrategia>(Objetivo);
		if (Suscriptor)
		{
			ANaveEnemiga* Nave = Cast<ANaveEnemiga>(Objetivo);
			if (Nave)
			{
				EnergiaTotalNavesEnemigas += Nave->GetEnergia();

			}

		}
	}
	PromEnerNavEnemigas = EnergiaTotalNavesEnemigas / contadorNavesEnemigas;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Promedio de energia de las naves enemigas: %f"), PromEnerNavEnemigas));
}