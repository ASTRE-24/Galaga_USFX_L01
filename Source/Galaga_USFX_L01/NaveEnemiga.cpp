
// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Galaga_USFX_L01Projectile.h"
#include "ActorComponentDisparo.h"
#include "TimerManager.h"

// Sets default values
ANaveEnemiga::ANaveEnemiga()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	// Create the mesh component
	mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	//mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	mallaNaveEnemiga->SetupAttachment(RootComponent);
	RootComponent = mallaNaveEnemiga;
	DisparoComponent = CreateDefaultSubobject<UActorComponentDisparo>(TEXT("DisparoComponent"));
	bShoulDispara = false;
	

	// Configurar la plantilla de part�culas (reemplaza "Path/To/Your/ParticleSystem" con la ruta correcta)
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (ParticleSystemAsset.Succeeded())
	{
		DestructionParticle=ParticleSystemAsset.Object;
		//DestructionParticle->Deactivate(); // Desactivar el sistema de part�culas inicialmente
	}
}



// Called when the game starts or when spawned
void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
	

}

// Called every frame
void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bShoulDispara)
	{
		if (DisparoComponent)
		{
			DisparoComponent->DispararProyectil();
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No se pudo disparar"));
		}
	}
}

void ANaveEnemiga::DestruirNave() 
{
	// Cargar la plantilla del sistema de part�culas desde el contenido de tu proyecto
	//static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (DestructionParticle)
	{
		// Spawnear el sistema de part�culas en la ubicaci�n de la nave enemiga
		UParticleSystemComponent* ParticulaFuego = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DestructionParticle, GetActorLocation(), FRotator::ZeroRotator, true);
		if (ParticulaFuego)
		{
			// Escalar el sistema de part�culas a la mitad
			ParticulaFuego->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));
			FTimerHandle ParticleTimerHandle;
			GetWorldTimerManager().SetTimer(ParticleTimerHandle, ParticulaFuego, &UParticleSystemComponent::Deactivate, 2.5f, false);
		}

	}
	else
	{
		// Si no se pudo cargar la plantilla del sistema de part�culas, mostrar un mensaje de error
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No se pudo cargar la plantilla del sistema de part�culas"));
	}

	// Destruir la nave enemiga
	Destroy();
}




