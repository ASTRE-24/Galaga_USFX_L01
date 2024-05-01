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
	
	constructorNaves->construirMovimientoNaveNodriza();
	constructorNaves->construirFormacionNavesEnemigas();
	constructorNaves->construirTipoDeArma();
	constructorNaves->construirTiposNavesEnemigas();
}

void ADirectorNaveNodriza::enviarConstructor(AActor* constructor)
{
	constructorNaves = Cast<IInterfaceBuilderNaveNodriza>(constructor);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Constructor enviado"));
}

ANaveEnemigaNodriza* ADirectorNaveNodriza::obtenerNave()
{
	return constructorNaves->getNaveNodriza();
}

