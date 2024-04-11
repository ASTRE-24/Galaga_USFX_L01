// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_L01GameMode.generated.h"

class ANaveEnemiga;
class ANaveEnemigaTransporte;
class ANaveEnemigaCaza;
class AInventoryActor;

UCLASS(MinimalAPI)
class AGalaga_USFX_L01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_USFX_L01GameMode();

public:
	//ANaveEnemiga* NaveEnemiga01;
	//ANaveEnemigaTransporte* NaveEnemigaTransporte01;
	ANaveEnemigaCaza* NaveEnemigaCaza01;
	FString GetUniqueNameForNave(); // Declaración de la función aquí
	void NaveInvisible();
	void HacerVisible(int32 Llave);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//Definicion de las naves enemigas en un array
	//TArray<ANaveEnemiga*> TANavesEnemigas;
	TArray<ANaveEnemigaCaza*> TANavesEnemigasCaza;
	TArray<ANaveEnemigaTransporte*> TANavesEnemigasTransporte;
	TMap<FString, ANaveEnemiga*> NaveEnemigas; // Aquí se declara el TMap para almacenar las naves enemigas
	TMap<int, FVector> UbicacionInventario; // Aquí se declara el TMap para almacenar las ubicaciones de los inventarios
	//TMap<int32, FVector> PosicionesNavesEnemigas; // Aquí se declara el TMap para almacenar las posiciones de las naves enemigas

private:
	
	int TiempoTranscurrido;
	
//public:
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;

};



