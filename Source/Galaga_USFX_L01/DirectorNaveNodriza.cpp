// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorNaveNodriza.h"

// Sets default values
ADirectorNaveNodriza::ADirectorNaveNodriza()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirectorNaveNodriza::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirectorNaveNodriza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirectorNaveNodriza::construirNaveNodriza()
{
	constructorNaveFase1->construirMovimientoNaveNodriza();
	constructorNaveFase1->construirMovimientoNavesEnemigas();
	constructorNaveFase1->construirTipoDeArma();
	constructorNaveFase1->construirTiposNavesEnemigas();
}

void ADirectorNaveNodriza::enviarConstructor(AActor* constructor)
{
	constructorNaveFase1 = Cast<IInterfaceBuilderNaveNodriza>(constructor);
}

ANaveEnemigaNodriza* ADirectorNaveNodriza::obtenerNave()
{
	return constructorNaveFase1->getNaveNodriza();
}

