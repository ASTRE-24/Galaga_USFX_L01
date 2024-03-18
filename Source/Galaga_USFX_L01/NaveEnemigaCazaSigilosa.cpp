// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCazaSigilosa.h"

ANaveEnemigaCazaSigilosa::ANaveEnemigaCazaSigilosa()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

}


void ANaveEnemigaCazaSigilosa::Mover(float DeltaTime) {
	// Se mueve un poco mas rapido en su estado de sigilo
}

void ANaveEnemigaCazaSigilosa::Atacar() {
	//ataques mas rapidos en su estado de sigilo por un tiempo
}

void ANaveEnemigaCazaSigilosa::Detectar() {
	//Deja el sigilo cuando ataca
}
