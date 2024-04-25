// Copyright Epic Games, Inc. All Rights Reserve

#include "Galaga_USFX_L01Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "NaveEnemiga.h"
#include "Obstaculo.h"
#include "InventoryActor.h"
#include "Galaga_USFX_L01Pawn.h"
#include "Particles/ParticleSystemComponent.h"
#include "Engine/StaticMesh.h"

AGalaga_USFX_L01Projectile::AGalaga_USFX_L01Projectile() 
{
	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Mehes/Balas/762x51_bullet_Bullet1.762x51_bullet_Bullet1'"));

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
	ProjectileMovement->InitialSpeed = 1500.f;
	ProjectileMovement->MaxSpeed = 1500.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f; // No gravity

	// Set the callback for when the projectile hits something
	

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
	// Declarar una variable para el componente de efecto de partículas
	

	// En el constructor de AGalaga_USFX_L01Projectile, después de configurar ProjectileMesh
	ExplosionParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ExplosionParticle"));
	ExplosionParticle->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'")); // Ruta al sistema de partículas en tu proyecto
	if (ParticleSystemAsset.Succeeded())
	{
		ExplosionParticle->SetTemplate(ParticleSystemAsset.Object);
		ExplosionParticle->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f)); // Escala a la mitad
	}

	
}

void AGalaga_USFX_L01Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation()); // simular la fuerza de la bala

		// Instanciar el efecto de partículas en la ubicación de la colisión
		if (ExplosionParticle)
		{
			ExplosionParticle->SetWorldLocation(Hit.ImpactPoint);
			ExplosionParticle->ActivateSystem();
		}

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Colision"));
	}

	Destroy();
}
void AGalaga_USFX_L01Projectile::NotifyHit(class UPrimitiveComponent*
	MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal,
	FVector NormalImpulse, const FHitResult& Hit)
{
	ANaveEnemiga* NaveEnemiga =
		Cast<ANaveEnemiga>(Other);
	if (NaveEnemiga != nullptr)
	{
		NaveEnemiga->DestruirNave();
		
	}

	AGalaga_USFX_L01Pawn* NaveJugador =
		Cast<AGalaga_USFX_L01Pawn>(Other);
	if (NaveJugador != nullptr)
	{
		//NaveJugador->Destroy();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Destruir nave jugador"));
	}
}

