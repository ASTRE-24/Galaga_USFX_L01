// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaEnemigaArma.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACapsulaEnemigaArma::ACapsulaEnemigaArma()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Crea el componente de malla estática
    UStaticMeshComponent* StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    SetRootComponent(StaticMeshComponent); // Establece el componente como raíz
	MovementComponent = CreateDefaultSubobject<UMovimientoVertical>(TEXT("MovimientoVertical")); // Crea el componente de movimiento vertical

    // Carga la malla estática desde el contenido del proyecto
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
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
void ACapsulaEnemigaArma::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACapsulaEnemigaArma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACapsulaEnemigaArma::NotifyHit(class UPrimitiveComponent*
    MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
    bool bSelfMoved, FVector HitLocation, FVector HitNormal,
    FVector NormalImpulse, const FHitResult& Hit)
{

    ANaveEnemiga* NaveEnemiga = Cast<ANaveEnemiga>(Other);
    if (NaveEnemiga)
    {
        Destroy();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Colision destruir perro"));
    }
    else return;
}