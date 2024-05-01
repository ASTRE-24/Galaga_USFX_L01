// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "InterfaceNaveNodriza.h"
#include "Armas.h"
#include "NaveEnemigaNodriza.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaNodriza : public ANaveEnemiga, public IInterfaceNaveNodriza
{
	GENERATED_BODY()

private:
	int numNavesGeneradas; //Numero de naves generadas;
	float tiempoGeneracionNaves; //Tiempo de generacion de naves
public:
	float Timer; //Timer para el movimiento de la nave
	float TiempoTranscurrido; //Tiempo transcurrido
	AArmas* arma;
	TArray<FString>NombresNavesAtaque; //Nombres de las naves de ataque
	TArray<FString>NombresNavesApoyo; //Nombres de las naves de apoyo
	TArray<FString>NombresNavesInformante; //Nombres de las naves informantes
	TArray<FVector> PosicionesNaves; //Naves de ataque
	TArray< ANaveEnemiga*> NavesEnemigas; //Naves enemigas
	FTimerHandle TimerNaves; //Timer para spawnear naves
	FTimerHandle TimerSpawnNaves; //Timer para spawnear naves
	FTimerHandle TimerInicial; //Timer para spawnear naves
	int indiceNave; //Indice de la nave
	int indicePosicion; //Indice de la posicion


public:
	ANaveEnemigaNodriza();

	FORCEINLINE int GetNumNavesGeneradas() const { return numNavesGeneradas; }
	FORCEINLINE float GetTiempoGeneracionNaves() const { return tiempoGeneracionNaves; }

	FORCEINLINE void SetNumNavesGeneradas(float _numNavesGeneradas) { numNavesGeneradas = _numNavesGeneradas; }
	FORCEINLINE void SetTiempoGeneracionNaves(float _tiempoGeneracionNaves) { tiempoGeneracionNaves = _tiempoGeneracionNaves; }

protected:
	virtual void Mover(float DeltaTime);
	virtual void Disparar();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	virtual void movimientoNaveNodriza() override;
	virtual void movimientoNavesEnemigas() override;
	virtual void tipoDeArma() override;
	virtual void tiposNavesEnemigas() override;
	virtual void retiroNaveNodriza() override;
	void repartirNaves();
	void posicionesIniciales(int g);
};
