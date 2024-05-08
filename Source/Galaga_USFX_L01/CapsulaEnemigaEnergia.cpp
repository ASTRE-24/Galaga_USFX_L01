// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaEnemigaEnergia.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaNodriza.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACapsulaEnemigaEnergia::ACapsulaEnemigaEnergia()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Crea el componente de malla estática
    UStaticMeshComponent* StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    SetRootComponent(StaticMeshComponent); // Establece el componente como raíz
    MovementComponent = CreateDefaultSubobject<UMovimientoVertical>(TEXT("MovimientoVertical")); // Crea el componente de movimiento vertical

    // Carga la malla estática desde el contenido del proyecto
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
    if (CylinderMeshAsset.Succeeded())
    {
        StaticMeshComponent->SetStaticMesh(CylinderMeshAsset.Object);
    }

    // Activa la simulación de física en el componente de malla estática
    StaticMeshComponent->SetSimulatePhysics(true);
    StaticMeshComponent->SetEnableGravity(false);
    StaticMeshComponent->SetNotifyRigidBodyCollision(true); // Activa notificaciones de colisión
}

// Called when the game starts or when spawned
void ACapsulaEnemigaEnergia::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACapsulaEnemigaEnergia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACapsulaEnemigaEnergia::NotifyHit(class UPrimitiveComponent*
    MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
    bool bSelfMoved, FVector HitLocation, FVector HitNormal,
    FVector NormalImpulse, const FHitResult& Hit)
{

    ANaveEnemiga* NaveEnemiga = Cast<ANaveEnemiga>(Other);
    if (NaveEnemiga)
    {
		if (!NaveEnemiga->IsA(ANaveEnemigaNodriza::StaticClass()))
        {
            usarCapsulaEnemiga(NaveEnemiga);
            Destroy();
        }
		else Destroy();
    }
    else Destroy();
    return;
}

void ACapsulaEnemigaEnergia::usarCapsulaEnemiga(ANaveEnemiga* naveEnemiga)
{
    int32 random = FMath::RandRange(0, 3);
    if (random == 0)
    {
        naveEnemiga->SetEnergia(100);
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, TEXT("Energia Nave Enemiga +100"));
    }
        
    else if (random == 1)
    {
        naveEnemiga->SetEnergia(120);
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, TEXT("Energia Nave Enemiga +120"));
    }
    else if (random == 2)
    {
        naveEnemiga->SetEnergia(150);
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, TEXT("Energia Nave Enemiga +150"));
    }
    else if (random == 3)
    {
        naveEnemiga->SetEnergia(200);
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, TEXT("Energia Nave Enemiga +200"));
    }
}

