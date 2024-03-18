// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveReabastecimientoEnergia.h"

ANaveReabastecimientoEnergia::ANaveReabastecimientoEnergia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_B.Shape_Wedge_B'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

}

void ANaveReabastecimientoEnergia::Mover(float DeltaTime)
{

}

void ANaveReabastecimientoEnergia::Escapar()
{

}

void ANaveReabastecimientoEnergia::RecargarEnergia()
{

}