// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estado.h"
#include "ActorComponentDisparo.h"
#include "Vehiculo.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AVehiculo : public AActor
{
	GENERATED_BODY()
private:
	IEstado* Estado;
	IEstado* EstadoVehiculoAereo;
	IEstado* EstadoVehiculoTerrestre;
	IEstado* EstadoVehiculoEspacial;

	UStaticMeshComponent* MallaVehiculo;
	
	
public:	
	// Sets default values for this actor's properties
	AVehiculo();
	IEstado* GetEstado();
	IEstado* GetEstadoVehiculoAereo();
	IEstado* GetEstadoVehiculoTerrestre();
	IEstado* GetEstadoVehiculoEspacial();
	FString GetNombreEstado();
	void SetEstado(IEstado* NuevoEstado);
	void Manejar();
	void Volar();
	void Navegar();
	void SuministrarCapsulas();
	void Disparar();
	float TiempoTranscurrido;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Disparo", meta = (AllowPrivateAccess = "true"))
	UActorComponentDisparo* DisparoComponent; // Declara el componente DisparoComponent

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    FString TipoDisparo;
	void ControlarEstado();

};
