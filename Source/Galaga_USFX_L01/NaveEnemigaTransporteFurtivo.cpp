// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporteFurtivo.h"

ANaveEnemigaTransporteFurtivo::ANaveEnemigaTransporteFurtivo()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

}

void ANaveEnemigaTransporteFurtivo:: evitarRadares() {

}

void ANaveEnemigaTransporteFurtivo::Destruirse() {
	//polimorfismo
}

void ANaveEnemigaTransporteFurtivo::Mover(float DeltaTime) {
	//polimorfismo para mover()
}