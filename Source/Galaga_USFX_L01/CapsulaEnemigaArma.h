// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovimientoVertical.h"
#include "InterfaceCapsulaEnemiga.h"
#include "CapsulaEnemigaArma.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ACapsulaEnemigaArma : public AActor, public IInterfaceCapsulaEnemiga
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACapsulaEnemigaArma();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movimiento")
	UMovimientoVertical* MovementComponent;
	bool bMoverse = false;

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
