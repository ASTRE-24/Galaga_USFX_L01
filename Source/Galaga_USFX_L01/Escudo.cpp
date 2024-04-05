// Fill out your copyright notice in the Description page of Project Settings.


#include "Escudo.h"

// Sets default values
AEscudo::AEscudo()
{// Set this actor to call Tick() every frame.
    PrimaryActorTick.bCanEverTick = false;

    // Carga el StaticMesh
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim.Shape_Trim'"));

    // Crea el componente de malla estática
    UStaticMeshComponent* Escudo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Escudo"));
    RootComponent = Escudo;

    // Verifica si se encontró el StaticMesh
    if (ShipMesh.Succeeded())
    {
        // Asigna el StaticMesh al componente de malla estática
        Escudo->SetStaticMesh(ShipMesh.Object);

        // Modifica la escala del componente de malla estática
        Escudo->SetWorldScale3D(FVector(1.0f, 3.0f, 1.0f)); // Aquí se ajusta la escala
    }

    
   
}

// Called when the game starts or when spawned
void AEscudo::BeginPlay()
{
	Super::BeginPlay();
	//SetLifeSpan(5.0f);
}

// Called every frame
void AEscudo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



