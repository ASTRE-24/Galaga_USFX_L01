// Copyright Epic Games, Inc. All Rights Reserve

#include "Galaga_USFX_L01Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "NaveEnemiga.h"
#include "Obstaculo.h"
#include "InventoryActor.h"
#include "Engine/StaticMesh.h"

AGalaga_USFX_L01Projectile::AGalaga_USFX_L01Projectile() 
{
	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));

	// Create mesh component for the projectile sphere
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	ProjectileMesh->SetupAttachment(RootComponent);
	ProjectileMesh->BodyInstance.SetCollisionProfileName("Projectile");
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AGalaga_USFX_L01Projectile::OnHit);		// set up a notification for when this component hits something
	RootComponent = ProjectileMesh;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	ProjectileMovement->UpdatedComponent = ProjectileMesh;
	ProjectileMovement->InitialSpeed = 2000.f;
	ProjectileMovement->MaxSpeed = 2000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f; // No gravity

	// Set the callback for when the projectile hits something
	

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AGalaga_USFX_L01Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());//simular la fuerza de la bala
		
	}
	ANaveEnemiga* nave = Cast<ANaveEnemiga>(OtherActor);

	if (nave != nullptr)
	{
		nave->Destroy();//destruir la nave enemiga
	}

	AObstaculo* obstaculo = Cast<AObstaculo>(OtherActor);
	if (obstaculo != nullptr)
	{
		obstaculo->Destroy();//destruir el obstaculo
	}

	AInventoryActor* item = Cast<AInventoryActor>(OtherActor);
	if (item != nullptr)
	{
		item->Destroy();//destruir el item
	}

	Destroy();
}

