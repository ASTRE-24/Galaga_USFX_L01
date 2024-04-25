// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"
#include "Galaga_USFX_L01Projectile.generated.h"

class UProjectileMovementComponent;
class UStaticMeshComponent;

UCLASS(config=Game)
class AGalaga_USFX_L01Projectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	UParticleSystemComponent* ExplosionParticle;
	UParticleSystem* ExplosionParticleTemplate;

public:
	AGalaga_USFX_L01Projectile();
	
	virtual void NotifyHit(class UPrimitiveComponent*
		MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
		bool bSelfMoved, FVector HitLocation, FVector HitNormal,
		FVector NormalImpulse, const FHitResult& Hit) override;

	/** Function to handle the projectile hitting something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	AActor* OriginActor;
	void SetOriginActor(AActor* _OriginActor) { OriginActor = _OriginActor; }
	AActor* GetOriginActor() { return OriginActor; }
	/** Returns ProjectileMesh subobject **/
	FORCEINLINE UStaticMeshComponent* GetProjectileMesh() const { return ProjectileMesh; }
	/** Returns ProjectileMovement subobject **/
	FORCEINLINE UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

