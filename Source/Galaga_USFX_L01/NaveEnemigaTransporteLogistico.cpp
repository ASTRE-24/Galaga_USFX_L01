// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporteLogistico.h"

ANaveEnemigaTransporteLogistico::ANaveEnemigaTransporteLogistico()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

}

void ANaveEnemigaTransporteLogistico::Mover(float DeltaTime) {

}

void ANaveEnemigaTransporteLogistico::Escapar() {

}

void ANaveEnemigaTransporteLogistico::Atacar() {

}

void ANaveEnemigaTransporteLogistico::Destruirse() {

}

void ANaveEnemigaTransporteLogistico::entregarSuministros() {

}