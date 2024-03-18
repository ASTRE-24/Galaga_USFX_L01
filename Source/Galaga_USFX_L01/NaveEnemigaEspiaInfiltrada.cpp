// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspiaInfiltrada.h"

ANaveEnemigaEspiaInfiltrada::ANaveEnemigaEspiaInfiltrada()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

}

void ANaveEnemigaEspiaInfiltrada::Mover(float DeltaTime)
{

}

void ANaveEnemigaEspiaInfiltrada::Atacar()
{

}

void ANaveEnemigaEspiaInfiltrada::Escapar()
{

}


void ANaveEnemigaEspiaInfiltrada::CambiarDisfraz()
{

}