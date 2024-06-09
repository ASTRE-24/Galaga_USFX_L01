
// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Galaga_USFX_L01Projectile.h"
#include "ActorComponentDisparo.h"
#include "TimerManager.h"
#include "BatallaEstrategy.h"
#include "Controlador.h"


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
	MovementComponent = CreateDefaultSubobject<UMovimentoNavesEnemigas>(TEXT("MovementComponent"));
	bShoulDispara = true;
	velocidad = 100;
	bMoverse = false;
	bMovimiento = true;
	energia = 100.0f;
	tipoArma = "";
	

	// Configurar la plantilla de partículas (reemplaza "Path/To/Your/ParticleSystem" con la ruta correcta)
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (ParticleSystemAsset.Succeeded())
	{
		DestructionParticle=ParticleSystemAsset.Object;
		//DestructionParticle->Deactivate(); // Desactivar el sistema de partículas inicialmente
	}
}

void ANaveEnemiga::EstablecerControlador(IControlador* myControlador)
{
	Controlador = myControlador;
}

void ANaveEnemiga::CambiarEstrategia(AActor* myEstrategia)
{
	Estrategia = Cast<IBatallaEstrategy>(myEstrategia);
	//Log Error if the cast failed
	if (!Estrategia)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green,
			TEXT("No se pudo hacer el Cast"));
		
	}
}

void ANaveEnemiga::EjecutarEstrategia()
{
	if (!Estrategia)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red,
			TEXT("Error al cargar la estrategia"));return;
		//Execute the current Strategy Maneuver
	}
	Estrategia->MoverseYDisparar(this);
}

// Called when the game starts or when spawned
void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
	TipoMovimiento = "";

}

void ANaveEnemiga::EnergiaBaja()
{
	
	if (energia <= 80)
	{
		Controlador->Notificar(this, "Energia 80%");
		energia = 100;
	}
}

// Called every frame
void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	EnergiaBaja();
	if (bMovimiento)
	{
		if (TipoMovimiento == "ZigZag")
		    MovementComponent->movimientoZigzag(DeltaTime);
		else if (TipoMovimiento == "Arco")
			MovementComponent->movimientoLineal(DeltaTime);
		
	}
	if (bShoulDispara)
	{
		if (tipoArma == "Normal")
		{
			DisparoComponent->ArmasDisparoNormal();
		}
		else if (tipoArma == "Doble")
		{
			DisparoComponent->ArmaDisparoDoble();
		}
		else if (tipoArma == "Triple")
		{
			DisparoComponent->ArmaDisparoTriple();
		}
		else if (tipoArma == "TripleAbanico")
		{
			DisparoComponent->ArmaDisparoTripleAbanico();
		}
		else if (tipoArma == "Rafaga")
		{
			DisparoComponent->ArmaDisparoRafaga();
		}
		
	}
}

void ANaveEnemiga::DestruirNave() 
{
	if (!LluviaDeObstaculos)
	{
		
	    UE_LOG(LogTemp, Error, TEXT("Lluvia de obstaculo no existe")); return;
	}
	// Cargar la plantilla del sistema de partículas desde el contenido de tu proyecto
	//static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (DestructionParticle)
	{
		// Spawnear el sistema de partículas en la ubicación de la nave enemiga
		UParticleSystemComponent* ParticulaFuego = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DestructionParticle, GetActorLocation(), FRotator::ZeroRotator, true);
		if (ParticulaFuego)
		{
			// Escalar el sistema de partículas a la mitad
			ParticulaFuego->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));
			FTimerHandle ParticleTimerHandle;
			GetWorldTimerManager().SetTimer(ParticleTimerHandle, ParticulaFuego, &UParticleSystemComponent::Deactivate, 2.5f, false);
		}

	}
	else
	{
		// Si no se pudo cargar la plantilla del sistema de partículas, mostrar un mensaje de error
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No se pudo cargar la plantilla del sistema de partículas"));
	}

	// Destruir la nave enemiga
	Destroy();
	LluviaDeObstaculos->UnSubscribe(this);
	ReduccionVida->UnSubscribe(this);
}

void ANaveEnemiga::Update()
{
	
	/*bMovimiento = false;
	bMoverse = true;
	bShoulDispara = true;
	int32 random = FMath::RandRange(0, 4);
	if (random == 0)
	{
		tipoArma = "Normal";
	}
	else if (random == 1)
	{
		tipoArma = "Doble";
	}
	else if (random == 2)
	{
		tipoArma = "Triple";
	}
	else if (random == 3)
	{
		tipoArma = "TripleAbanico";
	}
	else
	{
		tipoArma = "Normal";
	}*/
}

void ANaveEnemiga::SetLluviaObstaculo(ALluviaDeObstaculos* MyLluviaObstaculo)
{
	LluviaDeObstaculos = MyLluviaObstaculo;
	LluviaDeObstaculos->Subscribe(this);
}

void ANaveEnemiga::ActualizarEstrategia()
{
	//EjecutarEstrategia();
}

void ANaveEnemiga::SetReduccionVida(AReduccionVida* MyReduccionVida)
{
	ReduccionVida = MyReduccionVida;
	ReduccionVida->Subscribe(this);
}






