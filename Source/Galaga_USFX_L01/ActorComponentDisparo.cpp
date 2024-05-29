// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponentDisparo.h"
#include "Galaga_USFX_L01Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Galaga_USFX_L01Pawn.h"

// Sets default values for this component's properties
UActorComponentDisparo::UActorComponentDisparo()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bCanFire = true;
	FireRate = 2.f; // Ajusta según sea necesario
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
void UActorComponentDisparo::ArmasDisparoNormal()
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
			if (GetOwner()->IsA(AGalaga_USFX_L01Pawn::StaticClass()))
				FireRate = 0.2;
            World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &UActorComponentDisparo::ShotTimerExpired, FireRate);

            // Reproducir el sonido de disparo
            if (FireSound)
            {
                UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetOwner()->GetActorLocation());
            }
        }
    }
}

void UActorComponentDisparo::ArmaDisparoDoble()
{
	// Si es posible disparar
	if (bCanFire)
	{
		// Obtiene la rotación y la ubicación del propietario del componente
		FRotator FireRotation = GetOwner()->GetActorRotation() + FRotator(0.0f, 0.0f, 0.0f);
		FVector SpawnLocation = GetOwner()->GetActorLocation() + FireRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World)
		{
			// Calcula la posición de spawn para el primer proyectil (a la izquierda de la nave)
			const FVector SpawnLocationLeft = SpawnLocation - FireRotation.RotateVector(FVector(0.f, 60.f, 0.f));

			// Spawnea el primer proyectil
			AGalaga_USFX_L01Projectile* Proyectil1 = World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocationLeft, FireRotation);
			if (Proyectil1)
			{
				Proyectil1->SetOriginActor(GetOwner());
			}
			// Calcula la posición de spawn para el segundo proyectil (a la derecha de la nave)
			const FVector SpawnLocationRight = SpawnLocation + FireRotation.RotateVector(FVector(0.f, 60.f, 0.f));

			// Spawnea el segundo proyectil
			AGalaga_USFX_L01Projectile* Proyectil2 = World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocationRight, FireRotation);
			if (Proyectil2)
			{
				Proyectil2->SetOriginActor(GetOwner());
			}
			bCanFire = false;
			if (GetOwner()->IsA(AGalaga_USFX_L01Pawn::StaticClass()))
				FireRate = 0.2;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &UActorComponentDisparo::ShotTimerExpired, FireRate);

			// Reproducir el sonido de disparo
			if (FireSound)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetOwner()->GetActorLocation());
			}
		}
	}
}

void UActorComponentDisparo::ArmaDisparoTriple()
{
	// Si es posible disparar
	if (bCanFire)
	{
		// Obtiene la rotación y la ubicación del propietario del componente
		FRotator FireRotation = GetOwner()->GetActorRotation() + FRotator(0.0f, 0.0f, 0.0f);
		FVector SpawnLocation = GetOwner()->GetActorLocation() + FireRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World)
		{
			// Calcula la posición de spawn para el primer proyectil (a la izquierda de la nave)
			const FVector SpawnLocationLeft = SpawnLocation - FireRotation.RotateVector(FVector(0.f, 60.f, 0.f));

			// Spawnea el primer proyectil
			AGalaga_USFX_L01Projectile* Proyectil1 = World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocationLeft, FireRotation);
			if (Proyectil1)
			{
				Proyectil1->SetOriginActor(GetOwner());
			}
			//Calcula la posición de spawn para el segundo proyectil (en el centro de la nave)
			const FVector SpawnLocationCenter = SpawnLocation + FireRotation.RotateVector(FVector(0.f, 0.f, 0.f));

			// Spawnea el segundo proyectil
			AGalaga_USFX_L01Projectile* Proyectil2 = World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocationCenter, FireRotation);
			if (Proyectil2)
			{
				Proyectil2->SetOriginActor(GetOwner());
			}
			// Calcula la posición de spawn para el segundo proyectil (a la derecha de la nave)
			const FVector SpawnLocationRight = SpawnLocation + FireRotation.RotateVector(FVector(0.f, 60.f, 0.f));

			// Spawnea el segundo proyectil
			AGalaga_USFX_L01Projectile* Proyectil3 = World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocationRight, FireRotation);
			if (Proyectil3)
			{
				Proyectil3->SetOriginActor(GetOwner());
			}
			bCanFire = false;
			if (GetOwner()->IsA(AGalaga_USFX_L01Pawn::StaticClass()))
				FireRate = 0.2;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &UActorComponentDisparo::ShotTimerExpired, FireRate);

			// Reproducir el sonido de disparo
			if (FireSound)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetOwner()->GetActorLocation());
			}
		}
	}
}

void UActorComponentDisparo::ArmaDisparoTripleAbanico()
{
	// Si es posible disparar
	if (bCanFire)
	{
		// Obtiene la rotación y la ubicación del propietario del componente
		FRotator FireRotation = GetOwner()->GetActorRotation() + FRotator(0.0f, 0.0f, 0.0f);
		FVector SpawnLocation = GetOwner()->GetActorLocation() + FireRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World)
		{
			for (int i = 0; i < 3; ++i)
			{

				FRotator ModifiedRotation = FireRotation;
				// Modify rotation for each projectile
				ModifiedRotation.Yaw += (i - 1) * 20.0f; // Offset rotation by 10 degrees

				const FVector ModifiedLocation = GetOwner()->GetActorLocation() + ModifiedRotation.RotateVector(GunOffset);

				//// Spawn the projectile
				AGalaga_USFX_L01Projectile* Proyectil = World->SpawnActor<AGalaga_USFX_L01Projectile>(ModifiedLocation, ModifiedRotation);
				if (Proyectil)
				{
					Proyectil->SetOriginActor(GetOwner());
				}
			}
			bCanFire = false;
			if (GetOwner()->IsA(AGalaga_USFX_L01Pawn::StaticClass()))
				FireRate = 0.2;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &UActorComponentDisparo::ShotTimerExpired, FireRate);

			// Reproducir el sonido de disparo
			if (FireSound)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetOwner()->GetActorLocation());
			}
		}
	}
}

void UActorComponentDisparo::ArmaDisparoRafaga()
{
	// Si es posible disparar
	if (bCanFire)
	{
		// Obtiene la rotación y la ubicación del propietario del componente
		FRotator FireRotation = GetOwner()->GetActorRotation() + FRotator(0.0f, 0.0f, 0.0f);
		FVector SpawnLocation = GetOwner()->GetActorLocation() + FireRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World)
		{
			for (int i = 0; i < 5; ++i)
			{
				// Modify rotation for each projectile
				FRotator ModifiedRotation = FireRotation;
				ModifiedRotation.Yaw += (i - 2) * 10.0f; // Offset rotation by 10 degrees

				const FVector ModifiedLocation = GetOwner()->GetActorLocation() + ModifiedRotation.RotateVector(GunOffset);

				// Spawn the projectile
				AGalaga_USFX_L01Projectile* Proyectil = World->SpawnActor<AGalaga_USFX_L01Projectile>(ModifiedLocation, ModifiedRotation);
				if (Proyectil)
				{
					Proyectil->SetOriginActor(GetOwner());
				}
			}
			bCanFire = false;
			if (GetOwner()->IsA(AGalaga_USFX_L01Pawn::StaticClass()))
				FireRate = 0.2;
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
    //GetWorld()->GetTimerManager().SetTimer(TimerHandle_FireTimer, this, &UActorComponentDisparo::DispararProyectil, FireRate, true);
}