// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "InterfaceNaveNodriza.h"
#include "Armas.h"
#include "SolicitudDeNavesApoyo.h"
#include "SolicitudDeNavesAtaque.h"
#include "SolicitudDeNavesInformante.h"
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
	ASolicitudDeNaves* SolicitudDeNavesAtaque;
	ASolicitudDeNaves* SolicitudDeNavesApoyo;
	ASolicitudDeNaves* SolicitudDeNavesInformante;
	FString forma;
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
	FString tipoMovimiento; //Tipo de movimiento
	int categoriaNave; //Categoria de la nave


public:
	ANaveEnemigaNodriza();

	FORCEINLINE int GetNumNavesGeneradas() const { return numNavesGeneradas; }
	FORCEINLINE float GetTiempoGeneracionNaves() const { return tiempoGeneracionNaves; }
	FORCEINLINE FString GetTipoMovimiento() const { return tipoMovimiento; }
	FORCEINLINE TArray<FVector> GetPosicionesNaves() const { return PosicionesNaves; }
	FORCEINLINE TArray<ANaveEnemiga*> GetNavesEnemigas() const { return NavesEnemigas; }
	FORCEINLINE FString GetForma() const { return forma; }
	FORCEINLINE int GetCategiaNave() const { return categoriaNave; }

	FORCEINLINE void SetNumNavesGeneradas(float _numNavesGeneradas) { numNavesGeneradas = _numNavesGeneradas; }
	FORCEINLINE void SetTiempoGeneracionNaves(float _tiempoGeneracionNaves) { tiempoGeneracionNaves = _tiempoGeneracionNaves; }
	FORCEINLINE void SetTipoMovimiento(FString _tipoMovimiento) { tipoMovimiento = _tipoMovimiento; }
	FORCEINLINE void SetPosicionesNaves(TArray<FVector> _PosicionesNaves) { PosicionesNaves = _PosicionesNaves; }
	FORCEINLINE void SetForma(FString _forma) { forma = _forma; }
	FORCEINLINE void SetCategiaNave(int _categoriaNave) { categoriaNave = _categoriaNave; }

protected:
	virtual void Mover(float DeltaTime);
	virtual void Disparar();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	virtual void movimientoNaveNodriza() override;
	virtual void formacionNavesEnemigas(FString formacion) override;
	virtual void tipoDeArma() override;
	virtual void tiposNavesEnemigas() override;
	virtual void retiroNaveNodriza() override;
	void repartirNaves();
	void posicionesIniciales(int g);
};
