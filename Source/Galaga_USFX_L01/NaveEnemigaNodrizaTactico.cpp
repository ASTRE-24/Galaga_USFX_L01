// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodrizaTactico.h"

ANaveEnemigaNodrizaTactico::ANaveEnemigaNodrizaTactico()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

}

void ANaveEnemigaNodrizaTactico::Mover(float DeltaTime)
{

}

void ANaveEnemigaNodrizaTactico::DesplegarTropas()
{

}