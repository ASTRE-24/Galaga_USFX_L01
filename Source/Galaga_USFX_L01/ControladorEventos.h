// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Controlador.h"
#include "ControladorEventos.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AControladorEventos : public AActor, public IControlador
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AControladorEventos();
	class ANaveEnemiga* naveEnemiga;
	class Avehiculo* vehiculo;
	class AGalaga_USFX_L01Pawn* jugador;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	class AEstrategiaEnemigoAgresivo* EstrategiaAgresiva;
	class AEstrategiaEnemigoPasivo* EstrategiaPasiva;
	class AEstrategiaEnemigoMuyPeligroso* EstrategiaMuyPeligroso;
	class AEstrategiaEnemigoViolento* EstrategiaViolenta;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Notificar(AActor* Emisor, const FString& evento) override;
};
