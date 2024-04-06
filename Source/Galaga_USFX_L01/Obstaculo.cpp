// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstaculo.h"
#include "Galaga_USFX_L01Pawn.h"

// Sets default values
AObstaculo::AObstaculo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    // Carga el StaticMesh
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

    // Crea el componente de malla est�tica
    UStaticMeshComponent* Obstaculo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Obstaculo"));
    RootComponent = Obstaculo;

    // Verifica si se encontr� el StaticMesh
    if (ShipMesh.Succeeded())
    {
        // Asigna el StaticMesh al componente de malla est�tica
        Obstaculo->SetStaticMesh(ShipMesh.Object);

        // Modifica la escala del componente de malla est�tica
        Obstaculo->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f)); // Aqu� se ajusta la escala
    }
}

// Called when the game starts or when spawned
void AObstaculo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstaculo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    // Encuentra el objeto del jugador
    AGalaga_USFX_L01Pawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn<AGalaga_USFX_L01Pawn>();
    
    // Verifica si se encontr� al jugador
    if (PlayerPawn)
    {
        // Calcula la direcci�n hacia el jugador
        FVector DirectionToPlayer = PlayerPawn->GetActorLocation() - GetActorLocation();
        DirectionToPlayer.Normalize();

        // Calcula la nueva posici�n para el obst�culo
        FVector NewPosition = PlayerPawn->GetActorLocation() - (DirectionToPlayer * 200); // 100 es la distancia constante

        // Mueve el obst�culo hacia la nueva posici�n
        SetActorLocation(NewPosition);
    }
    //Obtener la referencia a un objeto de tipo AGalaga_USFX_L01Pawn
   

}

