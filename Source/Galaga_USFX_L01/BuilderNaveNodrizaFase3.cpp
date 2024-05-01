// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderNaveNodrizaFase3.h"


// Sets default values
ABuilderNaveNodrizaFase3::ABuilderNaveNodrizaFase3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuilderNaveNodrizaFase3::BeginPlay()
{
	Super::BeginPlay();
	naveNodriza = GetWorld()->SpawnActor<ANaveEnemigaNodriza>(ANaveEnemigaNodriza::StaticClass(), FVector(-900, 1250, 215), FRotator(0, 0, 0));
	naveNodriza->SetActorScale3D(FVector(0.5, 0.5, 0.5));
	naveNodriza->SetTipoMovimiento("Movimiento 3");
}

// Called every frame
void ABuilderNaveNodrizaFase3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderNaveNodrizaFase3::construirMovimientoNaveNodriza()
{
	naveNodriza->movimientoNaveNodriza();
}

void ABuilderNaveNodrizaFase3::construirFormacionNavesEnemigas()
{
	naveNodriza->formacionNavesEnemigas("Posicion 3");
}

void ABuilderNaveNodrizaFase3::construirTipoDeArma()
{
	naveNodriza->tipoDeArma();
}

void ABuilderNaveNodrizaFase3::construirTiposNavesEnemigas()
{
	naveNodriza->tiposNavesEnemigas();
}


class ANaveEnemigaNodriza* ABuilderNaveNodrizaFase3::getNaveNodriza()
{
	return naveNodriza;
}

