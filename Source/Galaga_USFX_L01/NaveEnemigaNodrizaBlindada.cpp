// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodrizaBlindada.h"

ANaveEnemigaNodrizaBlindada::ANaveEnemigaNodrizaBlindada()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

}

void ANaveEnemigaNodrizaBlindada::Mover(float DeltaTime)
{

}

void ANaveEnemigaNodrizaBlindada::ActivarEscudo()
{

}