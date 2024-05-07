// Fill out your copyright notice in the Description page of Project Settings.


#include "Armas.h"
#include "Galaga_Usfx_L01Projectile.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AArmas::AArmas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

    // Crea el componente de malla estática
    UStaticMeshComponent* Obstaculo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Obstaculo"));
    RootComponent = Obstaculo;

    // Verifica si se encontró el StaticMesh
    if (ShipMesh.Succeeded())
    {
        // Asigna el StaticMesh al componente de malla estática
        Obstaculo->SetStaticMesh(ShipMesh.Object);

        // Modifica la escala del componente de malla estática
        Obstaculo->SetWorldScale3D(FVector(0.1f, 0.1f, 0.1f)); // Aquí se ajusta la escala
    }
    MunicionInicial = 100;
    MunicionActual = MunicionInicial;
    MunicionMaxima = 100;
    bCanFire = true;
    FireRate = 1.5f;
    TipoDisparo = 0;
    GunOffset = FVector(120.0f, 0.0f, 0.0f);
    // Cache our sound effect
    static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
    FireSound = FireAudio.Object;
    

}

// Called when the game starts or when spawned
void AArmas::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArmas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
}



void AArmas::ArmasDisparoNormal(AActor* NaveDisparo)
{
    if (bCanFire)
    {

        // Obtiene la rotación y la ubicación del propietario del componente
        FRotator FireRotation = GetActorRotation() + FRotator(0.0f, -180.0f, 0.0f);
        FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

        UWorld* const World = GetWorld();
        if (World)
        {
            // Spawn del proyectil
            // (Asume que 'ProjectileClass' es la clase del proyectil que deseas disparar)
            AGalaga_USFX_L01Projectile* Proyectil = World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocation, FireRotation);
            if (Proyectil)
            {
                Proyectil->SetOriginActor(NaveDisparo);

            }
            // Configuración del temporizador para controlar la velocidad de disparo
            bCanFire = false;
            World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AArmas::ShotTimerExpired, FireRate);

            // Reproducir el sonido de disparo
            if (FireSound)
            {
                UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetActorLocation());
            }
        }
    }   
}

void AArmas::ArmaDisparoDoble(AActor* NaveDisparo)
{
    if (bCanFire)
    {


        // Obtiene la rotación y la ubicación del propietario del componente
        FRotator FireRotation = GetActorRotation() + FRotator(0.0f, 0.0f, 0.0f);
        FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

        UWorld* const World = GetWorld();
        if (World)
        {
            // Calcula la posición de spawn para el primer proyectil (a la izquierda de la nave)
            const FVector SpawnLocationLeft = SpawnLocation - FireRotation.RotateVector(FVector(0.f, 60.f, 0.f));

            // Spawnea el primer proyectil
            AGalaga_USFX_L01Projectile* Proyectil1 = World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocationLeft, FireRotation);
            if (Proyectil1)
            {
                Proyectil1->SetOriginActor(NaveDisparo);
            }
            // Calcula la posición de spawn para el segundo proyectil (a la derecha de la nave)
            const FVector SpawnLocationRight = SpawnLocation + FireRotation.RotateVector(FVector(0.f, 60.f, 0.f));

            // Spawnea el segundo proyectil
            AGalaga_USFX_L01Projectile* Proyectil2 = World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocationRight, FireRotation);
            if (Proyectil2)
            {
                Proyectil2->SetOriginActor(NaveDisparo);
            }
            // Configuración del temporizador para controlar la velocidad de disparo
            bCanFire = false;
            World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AArmas::ShotTimerExpired, FireRate);

            // Reproducir el sonido de disparo
            if (FireSound)
            {
                UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetActorLocation());
            }
        }
    }
}

void AArmas::ArmaDisparoTriple(AActor* NaveDisparo)
{
    if (bCanFire)
    {
        // Obtiene la rotación y la ubicación del propietario del componente
        FRotator FireRotation = GetActorRotation() + FRotator(0.0f, 0.0f, 0.0f);
        FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

        UWorld* const World = GetWorld();
        if (World)
        {

            // Calcula la posición de spawn para el primer proyectil (a la izquierda de la nave)
            const FVector SpawnLocationLeft = SpawnLocation - FireRotation.RotateVector(FVector(0.f, 60.f, 0.f));

            // Spawnea el primer proyectil
            AGalaga_USFX_L01Projectile* Proyectil1 = World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocationLeft, FireRotation);
            if (Proyectil1)
            {
                Proyectil1->SetOriginActor(NaveDisparo);
            }
            //Calcula la posición de spawn para el segundo proyectil (en el centro de la nave)
            const FVector SpawnLocationCenter = SpawnLocation + FireRotation.RotateVector(FVector(0.f, 0.f, 0.f));

            // Spawnea el segundo proyectil
            AGalaga_USFX_L01Projectile* Proyectil2 = World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocationCenter, FireRotation);
            if (Proyectil2)
            {
                Proyectil2->SetOriginActor(NaveDisparo);
            }
            // Calcula la posición de spawn para el segundo proyectil (a la derecha de la nave)
            const FVector SpawnLocationRight = SpawnLocation + FireRotation.RotateVector(FVector(0.f, 60.f, 0.f));

            // Spawnea el segundo proyectil
            AGalaga_USFX_L01Projectile* Proyectil3 = World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocationRight, FireRotation);
            if (Proyectil3)
            {
                Proyectil3->SetOriginActor(NaveDisparo);
            }
            // Configuración del temporizador para controlar la velocidad de disparo
            bCanFire = false;
            World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AArmas::ShotTimerExpired, FireRate);

            // Reproducir el sonido de disparo
            if (FireSound)
            {
                UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetActorLocation());
            }
        }
    }
}

void AArmas::ArmaDisparoTripleAbanico(AActor* NaveDisparo)
{
    
    if (bCanFire)
    {
        // Obtiene la rotación y la ubicación del propietario del componente
        FRotator FireRotation = GetActorRotation() + FRotator(0.0f, 0.0f, 0.0f);
        FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

        UWorld* const World = GetWorld();
        if (World)
        {
            for (int i = 0; i < 3; ++i)
            {

                FRotator ModifiedRotation = FireRotation;
                // Modify rotation for each projectile
                ModifiedRotation.Yaw += (i - 1) * 20.0f; // Offset rotation by 10 degrees

                const FVector ModifiedLocation = GetActorLocation() + ModifiedRotation.RotateVector(GunOffset);

                //// Spawn the projectile
                AGalaga_USFX_L01Projectile* Proyectil = World->SpawnActor<AGalaga_USFX_L01Projectile>(ModifiedLocation, ModifiedRotation);
                if (Proyectil)
                {
                    Proyectil->SetOriginActor(NaveDisparo);
                }
            }
            // Configuración del temporizador para controlar la velocidad de disparo
            bCanFire = false;
            World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AArmas::ShotTimerExpired, FireRate);

            // Reproducir el sonido de disparo
            if (FireSound)
            {
                UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetActorLocation());
            }
        }
    }
}

void AArmas::ShotTimerExpired()
{
	bCanFire = true;
}

void AArmas::SeguirNave(FVector posicion, FRotator rotacion)
{
	SetActorLocation(posicion);
	SetActorRotation(rotacion);
}

