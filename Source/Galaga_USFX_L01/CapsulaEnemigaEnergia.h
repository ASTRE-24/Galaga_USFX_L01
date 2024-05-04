// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfaceCapsulaEnemiga.h"
#include "MovimientoVertical.h"
#include "CapsulaEnemigaEnergia.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ACapsulaEnemigaEnergia : public AActor, public IInterfaceCapsulaEnemiga
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACapsulaEnemigaEnergia();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movimiento")
	UMovimientoVertical* MovementComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyHit(class UPrimitiveComponent*
		MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
		bool bSelfMoved, FVector HitLocation, FVector HitNormal,
		FVector NormalImpulse, const FHitResult& Hit) override;
	virtual void usarCapsulaEnemiga(ANaveEnemiga* naveEnemiga) override;
};
