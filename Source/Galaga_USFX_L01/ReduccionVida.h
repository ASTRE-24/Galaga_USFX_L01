// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Notificador.h"
#include "ReduccionVida.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API AReduccionVida : public ANotificador
{
	GENERATED_BODY()

public:
	class AEstrategiaEnemigoAgresivo* EstrategiaAgresiva;
	class AEstrategiaEnemigoPasivo* EstrategiaPasiva;
	class AEstrategiaEnemigoMuyPeligroso* EstrategiaMuyPeligroso;
	class AEstrategiaEnemigoViolento* EstrategiaViolenta;
	float TimeObstaculo;
	AReduccionVida();
	int flags;
protected:
	// Called when the game starts or when spawned

	float PromEnerNavEnemigas;
	virtual void BeginPlay() override;
	void VidaPromedioNaveEnemiga();

public:
	virtual void Tick(float DeltaTime) override;
	void CambioDeEstrategia();
	void SetTimeObstaculo(float NewTimeObstaculo);
};
