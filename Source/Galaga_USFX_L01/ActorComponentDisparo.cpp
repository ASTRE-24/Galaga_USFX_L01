// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponentDisparo.h"
#include "Galaga_USFX_L01Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UActorComponentDisparo::UActorComponentDisparo()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bCanFire = true;
	FireRate = 2.0f; // Ajusta según sea necesario
	GunOffset = FVector(120.0f, 0.0f, 0.0f); // Ajusta según sea necesario

    // Cache our sound effect
    static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
    FireSound = FireAudio.Object;
	// ...
}


// Called when the game starts
void UActorComponentDisparo::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActorComponentDisparo::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Dispara un proyectil
void UActorComponentDisparo::DispararProyectil()
{
    // Si es posible disparar
    if (bCanFire)
    {
        // Obtiene la rotación y la ubicación del propietario del componente
        FRotator FireRotation = GetOwner()->GetActorRotation()+FRotator(0.0f,0.0f,0.0f);
        FVector SpawnLocation = GetOwner()->GetActorLocation() + FireRotation.RotateVector(GunOffset);

        UWorld* const World = GetWorld();
        if (World)
        {
            // Spawn del proyectil
            // (Asume que 'ProjectileClass' es la clase del proyectil que deseas disparar)
            AGalaga_USFX_L01Projectile* Proyectil = World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocation, FireRotation);
            if (Proyectil)
            {
				Proyectil->SetOriginActor(GetOwner());
				
			}
            // Configuración del temporizador para controlar la velocidad de disparo
            bCanFire = false;
            World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &UActorComponentDisparo::ShotTimerExpired, FireRate);

            // Reproducir el sonido de disparo
            if (FireSound)
            {
                UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetOwner()->GetActorLocation());
            }
        }
    }
}

// Función para el temporizador de disparo expirado
void UActorComponentDisparo::ShotTimerExpired()
{
    bCanFire = true;
}

// Llama a esta función para iniciar el temporizador de disparo
void UActorComponentDisparo::StartFireTimer()
{
    if (!bCanFire)
    {
        return; // No hagas nada si no puedes disparar aún
    }

    // Configura un temporizador que dispara cada cierto tiempo
    GetWorld()->GetTimerManager().SetTimer(TimerHandle_FireTimer, this, &UActorComponentDisparo::DispararProyectil, FireRate, true);
}