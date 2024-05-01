// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "SolicitudDeNaves.generated.h"

UCLASS(abstract)
class GALAGA_USFX_L01_API ASolicitudDeNaves : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASolicitudDeNaves();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Crear una nave enemiga, metodo virtual puro
	virtual ANaveEnemiga* CrearNaveEnemiga(FString NombreNave) PURE_VIRTUAL(ASolicitudDeNaves::CrearNaveEnemiga, return nullptr;);
	//Ordena la nave enemiga y retorne la nave enemiga de una categoria especifica
	ANaveEnemiga* OrdenarNaveEnemiga(FString Categoria);
};
