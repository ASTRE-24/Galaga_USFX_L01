// Fill out your copyright notice in the Description page of Project Settings.


#include "SolicitudDeNaves.h"

// Sets default values
ASolicitudDeNaves::ASolicitudDeNaves()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASolicitudDeNaves::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASolicitudDeNaves::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ANaveEnemiga* ASolicitudDeNaves::OrdenarNaveEnemiga(FString Categoria, FVector Pocision, FRotator Rotacion)
{
	//crear una nave enemiga
	ANaveEnemiga* NaveEnemiga = CrearNaveEnemiga(Categoria, Pocision, Rotacion);
	return NaveEnemiga;
}

