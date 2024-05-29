// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "SolicitudDeNavesApoyo.h"
#include "SolicitudDeNavesAtaque.h"
#include "SolicitudDeNavesInformante.h"
#include "InventarioAFactory.h"
#include "Obstaculo.h"
#include "JugadorCapsula.h"
#include "EnemigoCapsula.h"
#include "LluviaDeObstaculos.h"
#include "ReduccionVida.h"
#include "Subscriber.h"
#include "Vehiculo.h"
#include "SpawnFacade.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ASpawnFacade : public AActor, public ISubscriber
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnFacade();
	ASolicitudDeNavesApoyo* navesApoyo;
	ASolicitudDeNavesAtaque* navesAtaque;
	ASolicitudDeNavesInformante* navesInformante;
	AObstaculo* obstaculoMapa;
	IInventarioAFactory* inventarioFactory;
	AVehiculo* VehiculoNeutral;

	TArray<ANaveEnemiga*> navesEnemigas;
	TArray<AObstaculo*> obstaculos;
	TArray<AActor*> capsulas;
	TMap<int, FVector> UbicacionInventario;
	TArray<FVector> PosicionesNaves;
	ALluviaDeObstaculos* lluviaObstaculos;
	AReduccionVida* reduccionVida;
	FTimerHandle TimerHandle_LluviaObstaculos;
	FTimerHandle TimerHandle_RetornarPosicion;
	float TiempoTranscurrido;
	float TiempoCapsulas;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void IniciarJuego();

private:
	void invocarNaves();
	void invocarObstaculos();
	void invocarCapsula();
	void CrearVehiculoNeutral();
	void posiciones();
	void realizaTareas(TArray<class ANaveEnemiga*> _NavesEnemigas, 
		TArray<class AObstaculo*> _Obstaculos, TArray<class AActor*> _Capsulas);
	void CrearLluviaObstaculos();
	void RetornarPosicion();
	void Update() override;
	virtual void Destroyed() override;
};
