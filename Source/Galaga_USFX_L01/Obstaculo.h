// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstaculo.generated.h"

UCLASS(abstract)
class GALAGA_USFX_L01_API AObstaculo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstaculo();
	float damage;
	float tiempoGeneracion;
	float velocidad;
	float limiteCaida;
	FVector posicion;
	bool bMoverse;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* CollisionComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Banderas
	float distanciaObs;
	virtual void movimientoObstaculo(float deltatime) PURE_VIRTUAL(AObstaculo::movimientoObstaculo, );
	virtual float danioObstaculo() PURE_VIRTUAL(AObstaculo::danioObstaculo, return 0;);

};
