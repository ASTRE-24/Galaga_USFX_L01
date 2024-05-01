// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderNaveNodrizaFase2.h"

// Sets default values
ABuilderNaveNodrizaFase2::ABuilderNaveNodrizaFase2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuilderNaveNodrizaFase2::BeginPlay()
{
	Super::BeginPlay();
	naveNodriza = GetWorld()->SpawnActor<ANaveEnemigaNodriza>(ANaveEnemigaNodriza::StaticClass(), FVector(-900, 1250, 215), FRotator(0, 0, 0));
	naveNodriza->SetActorScale3D(FVector(0.5, 0.5, 0.5));
	naveNodriza->SetTipoMovimiento("Movimiento 2");
}

// Called every frame
void ABuilderNaveNodrizaFase2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderNaveNodrizaFase2::construirMovimientoNaveNodriza()
{
	naveNodriza->movimientoNaveNodriza();
}

void ABuilderNaveNodrizaFase2::construirFormacionNavesEnemigas()
{
	naveNodriza->formacionNavesEnemigas("Posicion 2");
}

void ABuilderNaveNodrizaFase2::construirTipoDeArma()
{
	naveNodriza->tipoDeArma();
}

void ABuilderNaveNodrizaFase2::construirTiposNavesEnemigas()
{
	naveNodriza->tiposNavesEnemigas();
}


class ANaveEnemigaNodriza* ABuilderNaveNodrizaFase2::getNaveNodriza()
{
	return naveNodriza;
}

