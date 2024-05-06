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
	class ABuilderConcretoPNReparar* ReparacionPorta;
	class ADirectorPortaNave* IngenieroPortaNave;
	class IInventarioAFactory* InventarioAB;
	class ADirectorNaveNodriza* DirectorNodriza;
	class ABuilderNaveNodrizaFase1* BuilderNodrizaFase1;
	class ABuilderNaveNodrizaFase2* BuilderNodrizaFase2;
	class ABuilderNaveNodrizaFase3* BuilderNodrizaFase3;
	class AEnemigoCapsula* CapsulaEnemiga;
public:
	//ANaveEnemiga* NaveEnemiga01;
	//ANaveEnemigaTransporte* NaveEnemigaTransporte01;
	ANaveEnemigaCaza* NaveEnemigaCaza01;
	FString GetUniqueNameForNave(); // Declaración de la función aquí
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void SapwnCapsulasEnemigas();

public:
	//Definicion de las naves enemigas en un array
	//TArray<ANaveEnemiga*> TANavesEnemigas;
	TArray<ANaveEnemigaCaza*> TANavesEnemigasCaza;
	TArray<ANaveEnemigaTransporte*> TANavesEnemigasTransporte;
	TArray<ANaveEnemiga*> NavesEnemigas; // Aquí se declara el TMap para almacenar las naves enemigas
	TMap<int, FVector> UbicacionInventario; // Aquí se declara el TMap para almacenar las ubicaciones de los inventarios
	TArray<FString> NombresNavesAtaque; // Aquí se declara el TArray para almacenar los nombres de las naves enemigas de ataque
	TArray<FString> NombresNavesApoyo; // Aquí se declara el TArray para almacenar los nombres de las naves enemigas de apoyo
	TArray<FString> NombresNavesInformante; // Aquí se declara el TArray para almacenar los nombres de las naves enemigas de informante
	TArray<FVector> posicionCapsulasEnemigas; // Aquí se declara el TArray para almacenar las posiciones de las cápsulas enemigas
	FTimerHandle TimerCapsulas;

private:
	
	int TiempoTranscurrido;
	
//public:
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;

};



