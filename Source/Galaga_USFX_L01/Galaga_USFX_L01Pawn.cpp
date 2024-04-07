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
#include "Escudo.h"
#include "ActorSpawnerComponent.h"
#include "Obstaculo.h"

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
	PresionarTecla = 0;
	Multiplicador = 0;
	//Inicializar Banderas
	bCanFire = true;
	bDisparoDoble = false;
	bChocaYDestruye = false;
	bChocaYControla = false;
	bChocaYMeDestruyo = false;
	bChocarYAtravesar = false;


	// Inicializacion para componente de Escudo
	ActorSpawnerComponent = CreateDefaultSubobject<UActorSpawnerComponent>(TEXT("ActorSpawnerComponent"));
	if (ActorSpawnerComponent)
	{
		// Adjunta el ActorSpawnerComponent al RootComponent o a cualquier componente que desees
		ActorSpawnerComponent->SetupAttachment(RootComponent);
	}

	NumProyectilesDisparados = 0;
	MaxProyectilesDisparados = 25; //Establece el n�mero m�ximo de proyectiles disparados
	MyInventory =
		CreateDefaultSubobject<UInventoryComponent>("MyInventory");
	//NumItems = 0;
	InicialPosicion = FVector(-790.0f,10.0f, 215.0f);
	lastInput = FVector2D::ZeroVector;
	AlturaSalto = 215 + 300.0f;
	//Entrada para movimiento diagonal

	
	
	
	MoveDiagonalBindingForward = FInputAxisKeyMapping("MoveDiagonalForward", EKeys::Q, 1.f);
	MoveDiagonalBindingForward2 = FInputAxisKeyMapping("MoveDiagonalForward", EKeys::C, -1.f);
	MoveDiagonalBindingRight = FInputAxisKeyMapping("MoveDiagonalRight", EKeys::E, 1.f);
	MoveDiagonalBindingRight2 = FInputAxisKeyMapping("MoveDiagonalRight", EKeys::Z, -1.f);
	Retornar = FInputActionKeyMapping("ReturnToInitialPosition", EKeys::G, 0, 0, 0, 0);
	Jump = FInputActionKeyMapping("Saltar", EKeys::T, 0, 0, 0, 0);
	ChocaDestruye = FInputActionKeyMapping("ChocaYDestruye", EKeys::V, 0, 0, 0, 0);
	ChocaControla = FInputActionKeyMapping("ChocaYControla", EKeys::B, 0, 0, 0, 0);
	ChocaMeDestruyo = FInputActionKeyMapping("ChocaYMeDestruyo", EKeys::N, 0, 0, 0, 0);
	ChocarAtravesar = FInputActionKeyMapping("ChocarYAtravesar", EKeys::M, 0, 0, 0, 0);

}

void AGalaga_USFX_L01Pawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	
	GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(
		MoveDiagonalBindingForward);
	GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(
		MoveDiagonalBindingForward2);
	GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(
		MoveDiagonalBindingRight);
	GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(
		MoveDiagonalBindingRight2);

	UPlayerInput::AddEngineDefinedActionMapping(Retornar);
	UPlayerInput::AddEngineDefinedActionMapping(Jump);
	UPlayerInput::AddEngineDefinedActionMapping(ChocaControla);
	UPlayerInput::AddEngineDefinedActionMapping(ChocaDestruye);
	UPlayerInput::AddEngineDefinedActionMapping(ChocaMeDestruyo);
	UPlayerInput::AddEngineDefinedActionMapping(ChocarAtravesar);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);
	//Entrada para movimiento diagonal
	PlayerInputComponent->BindAxis("MoveDiagonalRight", this, &AGalaga_USFX_L01Pawn::MoveDiagonalRight);
	PlayerInputComponent->BindAxis("MoveDiagonalForward", this, &AGalaga_USFX_L01Pawn::MoveDiagonalForward);

	PlayerInputComponent->BindAction("DropItem",
		EInputEvent::IE_Pressed,this,
		&AGalaga_USFX_L01Pawn::DropItem);

	PlayerInputComponent->BindAction("ReloadAmmo", IE_Pressed, this, &AGalaga_USFX_L01Pawn::ReloadAmmo);
	PlayerInputComponent->BindAction("ReloadEnergy", IE_Pressed, this, &AGalaga_USFX_L01Pawn::ReloadEnergy);
	PlayerInputComponent->BindAction("ReturnToInitialPosition", IE_Pressed, this, &AGalaga_USFX_L01Pawn::ReturnToInitialPosition);
	PlayerInputComponent->BindAction("Saltar", IE_Pressed, this, &AGalaga_USFX_L01Pawn::Saltar);
	PlayerInputComponent->BindAction("TeleportToMouse", IE_Pressed, this, &AGalaga_USFX_L01Pawn::TeleportToMouse);
	PlayerInputComponent->BindAction("OnSpawnActor", IE_Pressed, this, &AGalaga_USFX_L01Pawn::OnSpawnActor);
	PlayerInputComponent->BindAction("ActivarDisparoDoble", IE_Pressed, this, &AGalaga_USFX_L01Pawn::ActivarDisparoDoble);
	PlayerInputComponent->BindAction("ChocaYDestruye", IE_Pressed, this, &AGalaga_USFX_L01Pawn::ChocaYDestruye);
	PlayerInputComponent->BindAction("ChocaYControla", IE_Pressed, this, &AGalaga_USFX_L01Pawn::ChocaYControla);
	PlayerInputComponent->BindAction("ChocaYMeDestruyo", IE_Pressed, this, &AGalaga_USFX_L01Pawn::ChocaYMeDestruyo);
	PlayerInputComponent->BindAction("ChocarYAtravesar", IE_Pressed, this, &AGalaga_USFX_L01Pawn::ChocarYAtravesar);


}


void AGalaga_USFX_L01Pawn::Tick(float DeltaSeconds)
{
	
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	// Combine the lastInput vector with the movement input
	FVector CombinedMovement = FVector(lastInput.Y, lastInput.X, 0.f) + FVector(ForwardValue, RightValue, 0.f);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = CombinedMovement.GetClampedToMaxSize(1.0f);

	// Calculate movement
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
	
	//Super::Tick(DeltaSeconds);
	float len = lastInput.Size();
	// Si la entrada del jugador es mayor que 1, normal�cela
	if (len > 1.f)
	{
		lastInput /= len;
	}
	//Poner a cero los �ltimos valores de entrada 
	lastInput = FVector2D(0.f, 0.f);


	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Tipo de Disparo
	
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
			if (bDisparoDoble) {
				
				if (World != nullptr)
				{
					// Calcula la posici�n de spawn para el primer proyectil (a la izquierda de la nave)
					const FVector SpawnLocationLeft = SpawnLocation - FireRotation.RotateVector(FVector(0.f, 60.f, 0.f));

					// Spawnea el primer proyectil
					World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocationLeft, FireRotation);

					// Calcula la posici�n de spawn para el segundo proyectil (a la derecha de la nave)
					const FVector SpawnLocationRight = SpawnLocation + FireRotation.RotateVector(FVector(0.f, 60.f, 0.f));

					// Spawnea el segundo proyectil
					World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocationRight, FireRotation);

					// Intenta reproducir el sonido si est� especificado
					if (FireSound != nullptr)
					{
						UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
					}

				}
			}
			else
			{
				
				if (World != nullptr)
				{
					// spawn the projectile
					// Spawn the three projectiles
					//float BulletSpacing = 100.0f; // Ajusta el valor seg�n sea necesario

					for (int i = 0; i < 3; ++i)
					{
						//World->SpawnActor<AGalaga_USFX_L01Projectile>(SpawnLocation, FireRotation);
						FRotator ModifiedRotation = FireRotation;
						// Modify rotation for each projectile
						ModifiedRotation.Yaw += (i - 1) * 20.0f; // Offset rotation by 10 degrees

						// Calcular la ubicaci�n de spawn de la bala actual
						//FVector BulletSpawnLocation = SpawnLocation + FireRotation.RotateVector(FVector(0.f, i * BulletSpacing, 0.f));

						// Spawn the projectile
						//World->SpawnActor<AGalaga_USFX_L01Projectile>(BulletSpawnLocation, FireRotation);


						const FVector ModifiedSpawnLocation = GetActorLocation() + ModifiedRotation.RotateVector(GunOffset);

						//// Spawn the projectile
						World->SpawnActor<AGalaga_USFX_L01Projectile>(ModifiedSpawnLocation, ModifiedRotation);
					}

				}
			}
			// Restablece el contador cuando se alcance el l�mite m�ximo
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
	UGameplayStatics::PlaySound2D(GetWorld(), Music, 0.1f); // Reproduce el sonido de la m�sica de fondo con un volumen de 0.3
	

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
	// Obt�n la ubicaci�n actual de la nave
	FVector ShipLocation = GetActorLocation();
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);

	// Ajusta la posici�n para centrar el objeto con respecto a la nave
	float DropDistance = 200.0f; // Distancia adicional para dejar caer el objeto
	FVector DropOffset = FVector(0.0f, 0.0f, ItemBounds.Z * 0.5f); // Ajusta la posici�n verticalmente para centrar el objeto
	FTransform PutDownLocation = FTransform(GetActorRotation(), ShipLocation + DropOffset +
		(RootComponent->GetForwardVector() * DropDistance)); // Combina la ubicaci�n de la nave con el desplazamiento vertical y horizontal

	Item->PutDown(PutDownLocation);

	//Verifica el inventario despu�s de soltar un objeto
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
	
	AObstaculo* Obstaculo = Cast<AObstaculo>(Other);
	
	if (Obstaculo != nullptr)
	{
		
		if (bChocaYControla)
		{
			Obstaculo->movimiento = true;
			Obstaculo->distanciaObs = Multiplicador * 125;
			Obstaculo->movimientoObstaculo();
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "EL OBSTACULO TE SEGUIRA");
			}
			Multiplicador += 1;
			return;
		}
		if(!bChocaYControla) Obstaculo->movimiento = false;

		if (bChocarYAtravesar)
		{
			Obstaculo->SetActorEnableCollision(false);
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "ATRAVESASTE ESTE OBSTACULO");
			}
			return;
		}
		if(!bChocarYAtravesar) Obstaculo->SetActorEnableCollision(true);

		if (bChocaYDestruye)
		{
			Obstaculo->Destroy();
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "SE DESTRUYO ESTE OBSTACULO");
			}
			return;
		}
		if (bChocaYMeDestruyo)
		{
			Destroy();

			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "NAVE DESTRUIDA: FIN DEL JUEGO");
			}
			return;
		}
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
	//bool bLooping = false; // Si el temporizador debe repetirse autom�ticamente o no
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

	
	
	//Verifica el inventario despu�s de recoger un objeto
	CheckInventory();
}

void AGalaga_USFX_L01Pawn::ReloadAmmo()
{
	// Bandera para verificar si se encontr� un objeto de munici�n
	bool bFoundAmmo = false;

	// Itera sobre los objetos en el inventario para encontrar uno de munici�n
	//AInventoryActor* InventoryItem = nullptr;
	
	for (AInventoryActor* InventoryItem : MyInventory->CurrentInventory)
	//while (MyInventory->CurrentInventory.Dequeue(InventoryItem))
	{
		// Intenta hacer un cast a AInventoryActorMunicion
		AInventoryActorMunicion* AmmoItem = Cast<AInventoryActorMunicion>(InventoryItem);
		if (AmmoItem)
		{
			// Se encontr� un objeto de munici�n en el inventario
			bFoundAmmo = true;

			// Se encontr� un objeto de munici�n en el inventario
			// Elimina el objeto de munici�n del inventario			
			MyInventory->RemoveFromInventory(AmmoItem);
			//NumProyectilesDisparados = 0; // Restablece el contador de proyectiles disparados.
			MaxProyectilesDisparados += 20; // Establece el n�mero m�ximo de proyectiles disparados
			int32 NumBalas = MaxProyectilesDisparados - NumProyectilesDisparados;
			bCanFire = true; // Permite al jugador disparar nuevamente.

			if (GEngine)
			{
				FString Message = FString::Printf(TEXT("Se recargaron +20 de municion te quedan %d"), NumBalas);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Message);
			}

			//NumItems -= 1; // Disminuye el contador de objetos en el inventario
			CheckInventory();

			// Sal del bucle ya que encontraste y manejaste un objeto de munici�n
			break;
		}
	}

	// Verifica si no se encontr� ning�n objeto de munici�n
	if (!bFoundAmmo)
	{
		// Muestra un mensaje indicando que no se encontr� ning�n objeto de munici�n
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
		// Obtiene el n�mero de objetos de inventario en el inventario del jugador
		
		int32 NumItems = MyInventory->CurrentInventory.Num();
		if (NumItems == 0)
		{
			// Muestra un mensaje indicando que no se encontr� ning�n objeto de munici�n
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, "No tienes objetos en el inventario");
			}
		}
		// Puedes hacer lo que quieras con NumItems, como mostrarlo en pantalla, usarlo en l�gica de juego, etc.
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
	// Bandera para verificar si se encontr� un objeto de munici�n
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
			// Se encontr� un objeto de munici�n en el inventario
			bFoundEnergy= true;
			// Se encontr� un objeto de Energia en el inventario
			// Elimina el objeto de munici�n del inventario
			MyInventory->RemoveFromInventory(EnergyItem);
			
			// Muestra un mensaje de depuraci�n
			if (GEngine)
			{
				//FString Message = FString::Printf(TEXT("Se recargaron %d de municion"), MaxProyectilesDisparados);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Se restablecio 100 pts de vida");
			}
			//NumItems -= 1;
			CheckInventory();
			// Sal del bucle ya que encontraste y manejaste un objeto de munici�n
			break;
		}
		
	}
	// Verifica si no se encontr� ning�n objeto de munici�n
	if (!bFoundEnergy)
	{
		// Muestra un mensaje indicando que no se encontr� ning�n objeto de munici�n
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "No tienes Energia para recargar");
		}
	}
}

void AGalaga_USFX_L01Pawn::ReturnToInitialPosition()
{
	// Calcula la direcci�n desde la posici�n actual hasta la posici�n inicial
	FVector ReturnDirection = InicialPosicion - GetActorLocation();
	ReturnDirection.Normalize();

	// Calcula la rotaci�n necesaria para que la nave apunte hacia la posici�n inicial
	FRotator TargetRotation = ReturnDirection.Rotation();

	// Interpola gradualmente la rotaci�n actual de la nave hacia la rotaci�n objetivo
	const float RotationInterpSpeed = 5.0f; // Velocidad de interpolaci�n de rotaci�n ajustable seg�n sea necesario
	FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), RotationInterpSpeed);

	// Aplica la nueva rotaci�n a la nave
	SetActorRotation(NewRotation);

	// Mueve la nave en la direcci�n de regreso a la posici�n inicial
	const float ReturnSpeed = 1000.0f; // Velocidad de retorno ajustable seg�n sea necesario
	const float DeltaTime = GetWorld()->GetDeltaSeconds();
	const FVector ReturnMovement = ReturnDirection * ReturnSpeed * DeltaTime;

	// Comprueba si la nave est� lo suficientemente cerca de la posici�n inicial
	const float ReturnDistanceThreshold = 10.0f; // Umbral de distancia ajustable seg�n sea necesario
	if (FVector::DistSquared(GetActorLocation(), InicialPosicion) <= FMath::Square(ReturnDistanceThreshold))
	{
		// La nave est� lo suficientemente cerca de la posici�n inicial, as� que establece su posici�n y rotaci�n exactamente en la posici�n inicial
		SetActorLocationAndRotation(InicialPosicion, FRotator(0,0,0));
	}
	else
	{
		// La nave todav�a no est� lo suficientemente cerca de la posici�n inicial, as� que sigue movi�ndola hacia all�
		SetActorLocation(GetActorLocation() + ReturnMovement);

		// Llama a esta funci�n nuevamente en el siguiente fotograma
		GetWorldTimerManager().SetTimerForNextTick([this]() { ReturnToInitialPosition(); });
	}
}

void AGalaga_USFX_L01Pawn::Saltar()
{
	 //AlturaSalto = GetActorLocation().Z+300.0f; // Ajusta la altura del salto seg�n sea necesario	
	// Mueve la nave en la direcci�n de regreso a la posici�n inicial
	
	

	const float ReturnSpeed = 1000.0f; // Velocidad de retorno ajustable seg�n sea necesario
	const float DeltaTime = GetWorld()->GetDeltaSeconds();
	const FVector ReturnMovement = FVector(0, 0, 1) * ReturnSpeed * DeltaTime;
	if (GetActorLocation().Z <= AlturaSalto)
	{

		SetActorLocation(GetActorLocation() + ReturnMovement);

		// Llama a esta funci�n nuevamente en el siguiente fotograma
		GetWorldTimerManager().SetTimerForNextTick([this]() {Saltar(); });

	}
	else
	{
       FinSaltar();
	}
}

void AGalaga_USFX_L01Pawn::FinSaltar()
{
	const float ReturnSpeed = 1000.0f; // Velocidad de retorno ajustable seg�n sea necesario
	const float DeltaTime = GetWorld()->GetDeltaSeconds();
	const FVector ReturnMovement = FVector(0, 0, -1) * ReturnSpeed * DeltaTime;
	if (GetActorLocation().Z >= AlturaSalto -300.0f )
	{

		SetActorLocation(GetActorLocation() + ReturnMovement);

		// Llama a esta funci�n nuevamente en el siguiente fotograma
		GetWorldTimerManager().SetTimerForNextTick([this]() {FinSaltar(); });

	}
	
}

void AGalaga_USFX_L01Pawn::MoveDiagonalForward(float amount)
{
	// Define la direcci�n del movimiento diagonal bas�ndose en la cantidad recibida
	FVector2D DiagonalInput( lastInput.X - amount, lastInput.Y + amount);

	// Normaliza el vector para asegurarse de que la velocidad del movimiento diagonal sea uniforme
	DiagonalInput.Normalize();

	// Asigna el vector de entrada diagonal a lastInput
	lastInput = DiagonalInput;
}

void AGalaga_USFX_L01Pawn::MoveDiagonalRight(float amount)
{
	// Define la direcci�n del movimiento diagonal bas�ndose en la cantidad recibida
	FVector2D DiagonalInput(lastInput.X + amount, lastInput.Y + amount);

	// Normaliza el vector para asegurarse de que la velocidad del movimiento diagonal sea uniforme
	DiagonalInput.Normalize();

	// Asigna el vector de entrada diagonal a lastInput
	lastInput = DiagonalInput;
}

void AGalaga_USFX_L01Pawn::TeleportToMouse()
{
	// Obtener el controlador del jugador
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (!PlayerController)
	{
		return;
	}

	// Verificar si se ha hecho clic
	if (!PlayerController->IsInputKeyDown(EKeys::LeftMouseButton))
	{
		return;
	}

	// Obtener la posici�n del clic en el mundo
	FVector ClickWorldLocation, ClickWorldDirection;
	PlayerController->DeprojectMousePositionToWorld(ClickWorldLocation, ClickWorldDirection);

	// Encontrar la intersecci�n con el plano XY a la altura deseada (Z = 215)
	FVector CameraLocation = PlayerController->PlayerCameraManager->GetCameraLocation();
	FVector RayEnd = ClickWorldLocation + (ClickWorldDirection * 10000.f); // Ajusta la distancia m�xima del rayo seg�n sea necesario

	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this); // Ignorar la propia nave en la intersecci�n
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, ClickWorldLocation, RayEnd, ECC_Visibility, CollisionParams);

	if (bHit)
	{
		// Asegurarse de que la altura Z sea 215
			HitResult.ImpactPoint.Z = 215;

		// Teletransportar la nave al punto de intersecci�n
		SetActorLocation(HitResult.ImpactPoint);
	}
}

void AGalaga_USFX_L01Pawn::OnSpawnActor()
{
	
	// Verifica si el ActorSpawnerComponent est� v�lido
	if (ActorSpawnerComponent)
	{
		// Llama a la funci�n SpawnEscudo del ActorSpawnerComponent
		ActorSpawnerComponent->SpawnEscudo();
	}
	
}


void AGalaga_USFX_L01Pawn::ActivarDisparoDoble()
{
	if (PresionarTecla == 0)
	{
		bDisparoDoble = true;
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Disparo Doble Activado");
		}
		PresionarTecla = 1;
	}
	else
	{
		bDisparoDoble = false;
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Disparo Doble Desactivado");
		}
		PresionarTecla = 0;
	}
}

//Funciones para activar las banderas de colision
void AGalaga_USFX_L01Pawn::ChocaYDestruye()
{
	
	bChocaYDestruye = true;
	//Descactivo las banderas activadas por otras teclas
	bChocarYAtravesar = false;
	bChocaYControla = false;
	bChocaYMeDestruyo = false;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Choca y Destruye: Activado");
		//informar al jugador que se desactivaron las otras banderas
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Se desactivaron las demas colisiones");
	}
}

void AGalaga_USFX_L01Pawn::ChocaYControla()
{
	bChocaYControla = true;
	//Descactivo las banderas activadas por otras teclas
	bChocaYDestruye = false;
	bChocaYMeDestruyo = false;
	bChocarYAtravesar = false;
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Choca y Controla: Activado");
		//informar al jugador que se desactivaron las otras banderas
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Se desactivaron las demas colisiones");
	}
}

void AGalaga_USFX_L01Pawn::ChocaYMeDestruyo()
{
	bChocaYMeDestruyo = true;
	//Descactivo las banderas activadas por otras teclas
	bChocaYDestruye = false;
	bChocaYControla = false;
	bChocarYAtravesar = false;
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Choca y Me Destruyo: Activado");
		//informar al jugador que se desactivaron las otras banderas
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Se desactivaron las demas colisiones");
	}
}

void AGalaga_USFX_L01Pawn::ChocarYAtravesar()
{
	bChocarYAtravesar = true;
	//Descactivo las banderas activadas por otras teclas
	bChocaYDestruye = false;
	bChocaYControla = false;
	bChocaYMeDestruyo = false;
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Chocar y Atravesar: Activado");
		//informar al jugador que se desactivaron las otras banderas
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Se desactivaron las demas colisiones");
	}
}


