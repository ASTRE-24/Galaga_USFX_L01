// Fill out your copyright notice in the Description page of Project Settings.


#include "Notificador.h"
#include "Subscriber.h"
#include "NaveEnemiga.h"

// Sets default values
ANotificador::ANotificador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANotificador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANotificador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*int32 ArraySize = Objetivos.Num();
	FString Mensaje = FString::Printf(TEXT("Size %d"), ArraySize);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Mensaje);*/
}

void ANotificador::Subscribe(AActor* Subscriber)
{
	Objetivos.Add(Subscriber);
}

void ANotificador::UnSubscribe(AActor* SuscriberToRemove)
{
	Objetivos.Remove(SuscriberToRemove);
}

void ANotificador::NotifySubscribers()
{
	for (AActor* Objetivo : Objetivos)
	{
		ISubscriber* Suscriptor = Cast<ISubscriber>(Objetivo);
		if (Suscriptor)
		{
			ANaveEnemiga* Nave = Cast<ANaveEnemiga>(Objetivo);
			if (Nave)
			{
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ObjetoNave"));
			}
			Suscriptor->Update();
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Notificando"));
		}
	}
}

void ANotificador::actualizarSubscribers()
{
	NotifySubscribers();
}