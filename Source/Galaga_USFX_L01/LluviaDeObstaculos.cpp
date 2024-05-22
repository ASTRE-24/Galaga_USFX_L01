// Fill out your copyright notice in the Description page of Project Settings.


#include "LluviaDeObstaculos.h"
#include "NaveEnemiga.h"
#include "Subscriber.h"

ALluviaDeObstaculos::ALluviaDeObstaculos()
{
	PrimaryActorTick.bCanEverTick = true;
	flags = 0;
}

void ALluviaDeObstaculos::BeginPlay()
{
	Super::BeginPlay();
}

void ALluviaDeObstaculos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (flags == 0)
	{
		VidaPromedioNaveEnemiga();
		if (PromEnerNavEnemigas < 50)
		{
			IniciarLluvia();
			flags = 1;
		}
	}
	
}

void ALluviaDeObstaculos::IniciarLluvia()
{
	NotifySubscribers();
}

void ALluviaDeObstaculos::SetTimeObstaculo(float NewTimeObstaculo)
{
	TimeObstaculo = NewTimeObstaculo;
	if (TimeObstaculo > 1.0f)
	IniciarLluvia();
}

void ALluviaDeObstaculos::VidaPromedioNaveEnemiga()
{
	
	float EnergiaTotalNavesEnemigas = 0;
	for (AActor* Objetivo : Objetivos)
	{
		ISubscriber* Suscriptor = Cast<ISubscriber>(Objetivo);
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