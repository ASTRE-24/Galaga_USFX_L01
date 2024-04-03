// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01Pawn.h"
#include "Galaga_USFX_L01Projectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "InventoryComponent.h"
#include "InventoryActor.h"
#include "InventoryActorMunicion.h"
#include "InventoryActorEnergia.h"

#include "Containers/Queue.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h" // Necesario para usar usar la musica de fondo

const FName AGalaga_USFX_L01Pawn::MoveForwardBinding("MoveForward");
const FName AGalaga_USFX_L01Pawn::MoveRightBinding("MoveRight");
const FName AGalaga_USFX_L01Pawn::FireForwardBinding("FireForward");
const FName AGalaga_USFX_L01Pawn::FireRightBinding("FireRight");

AGalaga_USFX_L01Pawn::AGalaga_USFX_L01Pawn()
{	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	
	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;
	bIsJumping = false;	

	NumProyectilesDisparados = 0;
	MaxProyectilesDisparados = 5; //Establece el número máximo de proyectiles disparados
	MyInventory =
		CreateDefaultSubobject<UInventoryComponent>("MyInventory");
	//NumItems = 0;
	InicialPosicion = FVector(-790.0f,10.0f, 215.0f);
}

void AGalaga_USFX_L01Pawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);

	PlayerInputComponent->BindAction("DropItem",
		EInputEvent::IE_Pressed,this,
		&AGalaga_USFX_L01Pawn::DropItem);

	PlayerInputComponent->BindAction("ReloadAmmo", IE_Pressed, this, &AGalaga_USFX_L01Pawn::ReloadAmmo);
	PlayerInputComponent->BindAction("ReloadEnergy", IE_Pressed, this, &AGalaga_USFX_L01Pawn::ReloadEnergy);
	PlayerInputComponent->BindAction("ReturnToInitialPosition", IE_Pressed, this, &AGalaga_USFX_L01Pawn::ReturnToInitialPosition);
	PlayerInputComponent->BindAction("Saltar", IE_Pressed, this, &AGalaga_USFX_L01Pawn::Saltar);

}


void AGalaga_USFX_L01Pawn::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	 //Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		
		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}
	
	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Try and fire a shot
	FireShot(FireDirection);

	/*if (GEngine)
	{
		FString Posicion = FString::Printf(TEXT(" Se cambio a X: %f, Y: %f, Z: %f"), 
			InicialPosicion.X, InicialPosicion.Y, InicialPosicion.Z);
		GEngine->AddOnScreenDebugMessage
		(-1, 5.f, FColor::Red, Posicion);
	}*/
}

void AGalaga_USFX_L01Pawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire==true && NumProyectilesDisparados<MaxProyectilesDisparados)
	{
		// Incrementa el contador de proyectiles disparados
		

		
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				// Spawn the three projectiles
				//float BulletSpacing = 100.0f; // Ajusta el valor según sea necesario

				for (int i = 0; i <3 ; ++i)
				{
					//World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocation, FireRotation);
					 FRotator ModifiedRotation = FireRotation;
					// Modify rotation for each projectile
					ModifiedRotation.Yaw += (i - 1) * 20.0f; // Offset rotation by 10 degrees

					// Calcular la ubicación de spawn de la bala actual
                    //FVector BulletSpawnLocation = SpawnLocation + FireRotation.RotateVector(FVector(0.f, i * BulletSpacing, 0.f));

                    // Spawn the projectile
                    //World->SpawnActor<AGalaga_USFX_L01Projectile>(BulletSpawnLocation, FireRotation);
                
            
					const FVector ModifiedSpawnLocation = GetActorLocation() + ModifiedRotation.RotateVector(GunOffset);

					//// Spawn the projectile
					World->SpawnActor<AGalaga_USFX_L01Projectile>(ModifiedSpawnLocation, ModifiedRotation);
				}
				
			}
			// Restablece el contador cuando se alcance el límite máximo
			if (NumProyectilesDisparados >= MaxProyectilesDisparados)
			{
				bCanFire = false;
				GetWorld()->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGalaga_USFX_L01Pawn::ShotTimerExpired, FireRate);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGalaga_USFX_L01Pawn::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}

void AGalaga_USFX_L01Pawn::ShotTimerExpired()
{
	// Restablece el contador y permite disparar de nuevo
	++NumProyectilesDisparados; // Incrementa el contador de proyectiles disparados en 1
	
	if (NumProyectilesDisparados >= MaxProyectilesDisparados)
	{
		//NumProyectilesDisparados = 0;
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "No tienes municiones");
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Presiona Q para recargar");
			

		}
	}
	bCanFire = true;
}

//Para que suene la musica de fondo
void AGalaga_USFX_L01Pawn::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::PlaySound2D(GetWorld(), Music, 0.1f); // Reproduce el sonido de la música de fondo con un volumen de 0.3
	

}

void AGalaga_USFX_L01Pawn::DropItem()
{
	if (MyInventory->CurrentInventory.Num() == 0)//MyInventory->CurrentInventory.IsEmpty()
	{
		/*if (GEngine)
		{
			FString Message = FString::Printf(TEXT("Tienes %d objetos en tu inventario"), NumItems);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, Message);
		}
		return;*/
		CheckInventory();
		return;
	}
	//AInventoryActor* Item = nullptr;
	//MyInventory->CurrentInventory.Dequeue(Item);
	AInventoryActor* Item = MyInventory->CurrentInventory.Last();
	//MyInventory->CurrentInventory.Last();
	MyInventory->RemoveFromInventory(Item);
	//NumItems-=1;
	// Obtén la ubicación actual de la nave
	FVector ShipLocation = GetActorLocation();
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);

	// Ajusta la posición para centrar el objeto con respecto a la nave
	float DropDistance = 200.0f; // Distancia adicional para dejar caer el objeto
	FVector DropOffset = FVector(0.0f, 0.0f, ItemBounds.Z * 0.5f); // Ajusta la posición verticalmente para centrar el objeto
	FTransform PutDownLocation = FTransform(GetActorRotation(), ShipLocation + DropOffset +
		(RootComponent->GetForwardVector() * DropDistance)); // Combina la ubicación de la nave con el desplazamiento vertical y horizontal

	Item->PutDown(PutDownLocation);

	//Verifica el inventario después de soltar un objeto
	CheckInventory();
}

void AGalaga_USFX_L01Pawn::NotifyHit(class UPrimitiveComponent*
	MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal,
	FVector NormalImpulse, const FHitResult& Hit)
{
	AInventoryActor* InventoryItem =
		Cast<AInventoryActor>(Other);
	if (InventoryItem != nullptr)
	{
		TakeItem(InventoryItem);
	}
}
void AGalaga_USFX_L01Pawn::TakeItem(AInventoryActor* InventoryItem)
{
	InventoryItem->PickUp();
	MyInventory->AddToInventory(InventoryItem);
	// Declarar un TimerHandle
	
	//NumItems+=1;	

	// Configurar el temporizador con SetTimer
	//float DelayInSeconds = 10.0f; // Tiempo de retraso en segundos
	//bool bLooping = false; // Si el temporizador debe repetirse automáticamente o no
	//AInventoryActorMunicion* AmmoItem = Cast<AInventoryActorMunicion>(InventoryItem);
	//if (AmmoItem)
	//{
 //     FTimerHandle MyTimerHandle1;
	//  GetWorldTimerManager().SetTimer(MyTimerHandle1, this, &AGalaga_USFX_L01Pawn::ReloadAmmo, DelayInSeconds, bLooping);
	//}

	//AInventoryActorEnergia* EnergyItem = Cast<AInventoryActorEnergia>(InventoryItem);
	//if (EnergyItem)
	//{
	//	FTimerHandle MyTimerHandle2;
	//	GetWorldTimerManager().SetTimer(MyTimerHandle2, this, &AGalaga_USFX_L01Pawn::ReloadEnergy, DelayInSeconds, bLooping);
	//}

	
	
	//Verifica el inventario después de recoger un objeto
	CheckInventory();
}

void AGalaga_USFX_L01Pawn::ReloadAmmo()
{
	// Bandera para verificar si se encontró un objeto de munición
	bool bFoundAmmo = false;

	// Itera sobre los objetos en el inventario para encontrar uno de munición
	//AInventoryActor* InventoryItem = nullptr;
	
	for (AInventoryActor* InventoryItem : MyInventory->CurrentInventory)
	//while (MyInventory->CurrentInventory.Dequeue(InventoryItem))
	{
		// Intenta hacer un cast a AInventoryActorMunicion
		AInventoryActorMunicion* AmmoItem = Cast<AInventoryActorMunicion>(InventoryItem);
		if (AmmoItem)
		{
			// Se encontró un objeto de munición en el inventario
			bFoundAmmo = true;

			// Se encontró un objeto de munición en el inventario
			// Elimina el objeto de munición del inventario			
			MyInventory->RemoveFromInventory(AmmoItem);
			//NumProyectilesDisparados = 0; // Restablece el contador de proyectiles disparados.
			MaxProyectilesDisparados += 20; // Establece el número máximo de proyectiles disparados
			int32 NumBalas = MaxProyectilesDisparados - NumProyectilesDisparados;
			bCanFire = true; // Permite al jugador disparar nuevamente.

			if (GEngine)
			{
				FString Message = FString::Printf(TEXT("Se recargaron +20 de municion te quedan %d"), NumBalas);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Message);
			}

			//NumItems -= 1; // Disminuye el contador de objetos en el inventario
			CheckInventory();

			// Sal del bucle ya que encontraste y manejaste un objeto de munición
			break;
		}
	}

	// Verifica si no se encontró ningún objeto de munición
	if (!bFoundAmmo)
	{
		// Muestra un mensaje indicando que no se encontró ningún objeto de munición
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "No tienes municion para recargar");
		}
	}
}

void AGalaga_USFX_L01Pawn::CheckInventory()
{
	
	// Verifica si el componente de inventario existe
	if (MyInventory)
	{
		// Obtiene el número de objetos de inventario en el inventario del jugador
		
		int32 NumItems = MyInventory->CurrentInventory.Num();
		if (NumItems == 0)
		{
			// Muestra un mensaje indicando que no se encontró ningún objeto de munición
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, "No tienes objetos en el inventario");
			}
		}
		// Puedes hacer lo que quieras con NumItems, como mostrarlo en pantalla, usarlo en lógica de juego, etc.
		else
		{
			if (GEngine)
			{
				FString Message = FString::Printf(TEXT("Tienes %d objetos en tu inventario"), NumItems);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, Message);
			}
		}
	}
	
}



void AGalaga_USFX_L01Pawn::ReloadEnergy()
{
	// Bandera para verificar si se encontró un objeto de munición
	bool bFoundEnergy = false;
	// Itera sobre los objetos en el inventario para encontrar uno de Energia
	//AInventoryActor* InventoryItem = nullptr;
	for (AInventoryActor* InventoryItem : MyInventory->CurrentInventory)
	//while (MyInventory->CurrentInventory.Dequeue(InventoryItem))
	{
		// Intenta hacer un cast a AInventoryActorEnergy
		AInventoryActorEnergia* EnergyItem = Cast<AInventoryActorEnergia>(InventoryItem);
		if (EnergyItem)
		{
			// Se encontró un objeto de munición en el inventario
			bFoundEnergy= true;
			// Se encontró un objeto de Energia en el inventario
			// Elimina el objeto de munición del inventario
			//MyInventory->RemoveFromInventory(EnergyItem);
			
			// Muestra un mensaje de depuración
			if (GEngine)
			{
				//FString Message = FString::Printf(TEXT("Se recargaron %d de municion"), MaxProyectilesDisparados);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Se restablecio 100 pts de vida");
			}
			//NumItems -= 1;
			CheckInventory();
			// Sal del bucle ya que encontraste y manejaste un objeto de munición
			break;
		}
		
	}
	// Verifica si no se encontró ningún objeto de munición
	if (!bFoundEnergy)
	{
		// Muestra un mensaje indicando que no se encontró ningún objeto de munición
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "No tienes Energia para recargar");
		}
	}
}

void AGalaga_USFX_L01Pawn::ReturnToInitialPosition()
{
	// Calcula la dirección desde la posición actual hasta la posición inicial
	FVector ReturnDirection = InicialPosicion - GetActorLocation();
	ReturnDirection.Normalize();

	// Calcula la rotación necesaria para que la nave apunte hacia la posición inicial
	FRotator TargetRotation = ReturnDirection.Rotation();

	// Interpola gradualmente la rotación actual de la nave hacia la rotación objetivo
	const float RotationInterpSpeed = 5.0f; // Velocidad de interpolación de rotación ajustable según sea necesario
	FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), RotationInterpSpeed);

	// Aplica la nueva rotación a la nave
	SetActorRotation(NewRotation);

	// Mueve la nave en la dirección de regreso a la posición inicial
	const float ReturnSpeed = 1000.0f; // Velocidad de retorno ajustable según sea necesario
	const float DeltaTime = GetWorld()->GetDeltaSeconds();
	const FVector ReturnMovement = ReturnDirection * ReturnSpeed * DeltaTime;

	// Comprueba si la nave está lo suficientemente cerca de la posición inicial
	const float ReturnDistanceThreshold = 10.0f; // Umbral de distancia ajustable según sea necesario
	if (FVector::DistSquared(GetActorLocation(), InicialPosicion) <= FMath::Square(ReturnDistanceThreshold))
	{
		// La nave está lo suficientemente cerca de la posición inicial, así que establece su posición y rotación exactamente en la posición inicial
		SetActorLocationAndRotation(InicialPosicion, FRotator(0,0,0));
	}
	else
	{
		// La nave todavía no está lo suficientemente cerca de la posición inicial, así que sigue moviéndola hacia allí
		SetActorLocation(GetActorLocation() + ReturnMovement);

		// Llama a esta función nuevamente en el siguiente fotograma
		GetWorldTimerManager().SetTimerForNextTick([this]() { ReturnToInitialPosition(); });
	}
}

void AGalaga_USFX_L01Pawn::Saltar()
{
	// Si la nave no está ya en un salto
	if (!bIsJumping)
	{
		// Realiza la lógica de salto aquí
		FVector JumpDirection = FVector(0.0f, 0.0f, 500); // Ajusta la altura del salto según sea necesario
		SetActorLocation(GetActorLocation() + JumpDirection);

		// Establece la bandera de salto en verdadero
		bIsJumping = true;
		FTimerHandle JumpTimerHandle;	
		// Programa una función para que la nave regrese al suelo después de un tiempo
		GetWorld()->GetTimerManager().SetTimer(JumpTimerHandle, this, &AGalaga_USFX_L01Pawn::FinSaltar, 5, false);
	}
}

void AGalaga_USFX_L01Pawn::FinSaltar()
{
	// Realiza la lógica de finalización del salto aquí
	FVector JumpDirection = FVector(0.0f, 0.0f, -500); // Ajusta la altura del descenso según sea necesario
	SetActorLocation(GetActorLocation() + JumpDirection);

	// Establece la bandera de salto en falso
	bIsJumping = false;
}