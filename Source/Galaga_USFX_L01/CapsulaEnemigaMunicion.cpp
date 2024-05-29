// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaEnemigaMunicion.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaNodriza.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACapsulaEnemigaMunicion::ACapsulaEnemigaMunicion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    // Crea el componente de malla estática
    UStaticMeshComponent* StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    SetRootComponent(StaticMeshComponent); // Establece el componente como raíz
    MovementComponent = CreateDefaultSubobject<UMovimientoVertical>(TEXT("MovimientoVertical")); // Crea el componente de movimiento vertical

    // Carga la malla estática desde el contenido del proyecto
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
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
void ACapsulaEnemigaMunicion::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACapsulaEnemigaMunicion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bMoverse)
    {
		MovementComponent->MoveVertical(DeltaTime);
		MovementComponent->MovimientoHorizontalArriba(DeltaTime);
	}   
}

void ACapsulaEnemigaMunicion::NotifyHit(class UPrimitiveComponent*
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

void ACapsulaEnemigaMunicion::usarCapsulaEnemiga(ANaveEnemiga* naveEnemiga)
{
    int32 random = FMath::RandRange(0, 3);
    if (random == 0)
    {
        naveEnemiga->SetMunicion(10);
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Turquoise, TEXT("Municion Nave Enemiga +10"));
    }

    else if (random == 1)
    {
        naveEnemiga->SetMunicion(12);
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Turquoise, TEXT("Municion Nave Enemiga +12"));
    }
    else if (random == 2)
    {
        naveEnemiga->SetMunicion(15);
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Turquoise, TEXT("Municion Nave Enemiga +15"));
    }
    else if (random == 3)
    {
        naveEnemiga->SetMunicion(20);
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Turquoise, TEXT("Municion Nave Enemiga +20"));
    }
}

