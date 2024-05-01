// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderNaveNodrizaFase1.h"
#include "TimerManager.h"

// Sets default values
ABuilderNaveNodrizaFase1::ABuilderNaveNodrizaFase1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuilderNaveNodrizaFase1::BeginPlay()
{
	Super::BeginPlay();
	naveNodriza = GetWorld()->SpawnActor<ANaveEnemigaNodriza>(ANaveEnemigaNodriza::StaticClass(), FVector(-900,1250,215), FRotator (0,0,0));
}

// Called every frame
void ABuilderNaveNodrizaFase1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderNaveNodrizaFase1::construirMovimientoNaveNodriza()
{
	naveNodriza->movimientoNaveNodriza();
}

void ABuilderNaveNodrizaFase1::construirMovimientoNavesEnemigas()
{
	naveNodriza->movimientoNavesEnemigas();
}

void ABuilderNaveNodrizaFase1::construirTipoDeArma()
{
	naveNodriza->tipoDeArma();
}

void ABuilderNaveNodrizaFase1::construirTiposNavesEnemigas()
{
	naveNodriza->tiposNavesEnemigas();
}


class ANaveEnemigaNodriza* ABuilderNaveNodrizaFase1::getNaveNodriza()
{
	return naveNodriza;
}
 

