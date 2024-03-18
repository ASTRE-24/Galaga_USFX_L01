// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspiaTactica.h"

ANaveEnemigaEspiaTactica::ANaveEnemigaEspiaTactica()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

}

void ANaveEnemigaEspiaTactica::Mover(float DeltaTime)
{

}

void ANaveEnemigaEspiaTactica::Atacar()
{

}

void ANaveEnemigaEspiaTactica::RecopilarInformacion()
{

}