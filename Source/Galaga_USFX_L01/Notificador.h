// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Notificador.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ANotificador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANotificador();
	float contadorNavesEnemigas;
	FORCEINLINE void SetContadorNavesEnemigas(float NewContadorNavesEnemigas);
protected:
	
	TArray<AActor*> Objetivos = TArray<AActor*>();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Subscribe(AActor* Subscriber);
	virtual void UnSubscribe(AActor* SubscriberToRemove);
	virtual void NotifySubscribers();
	virtual void NotificarCambioEstrategia();
	virtual void actualizarSubscribers();
};
