// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InventoryComponent.h"
#include "InventoryActor.h"
#include "GameFramework/PlayerInput.h"

#include "Galaga_USFX_L01Pawn.generated.h"

class UActorSpawnerComponent;
UCLASS(Blueprintable)
class AGalaga_USFX_L01Pawn : public APawn
{
	GENERATED_BODY()

	/* The mesh component */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ShipMeshComponent;

	/** The camera */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

public:
	AGalaga_USFX_L01Pawn();

	UPROPERTY()
	UInventoryComponent* MyInventory;
	UFUNCTION()
	void DropItem();
	UFUNCTION()
	void TakeItem(AInventoryActor* InventoryItem);
	UFUNCTION()
	virtual void NotifyHit(class UPrimitiveComponent* MyComp,
		AActor* Other, class UPrimitiveComponent* OtherComp,
		bool bSelfMoved, FVector HitLocation, FVector
		HitNormal, FVector NormalImpulse, const FHitResult&
		Hit) override;

	UFUNCTION()
	void ReloadAmmo();

	void ReturnToInitialPosition();

	void Saltar();
	void FinSaltar();
	//Movimiento en diagonal
	void MoveDiagonalRight(float amount);
	FInputAxisKeyMapping MoveDiagonalBindingRight;
	FInputAxisKeyMapping MoveDiagonalBindingRight2;

	void MoveDiagonalForward(float amount);
	FInputAxisKeyMapping MoveDiagonalBindingForward;
	FInputAxisKeyMapping MoveDiagonalBindingForward2;

	FInputActionKeyMapping  Retornar;
	FInputActionKeyMapping  Jump;

	void TeleportToMouse();

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite )
	FVector GunOffset;
	
	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float FireRate;

	/* The speed our ship moves around the level */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float MoveSpeed;

	/** Sound to play each time we fire */
	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound;

	// Begin Actor Interface
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End Actor Interface

	/* Fire a shot in the specified direction */
	void FireShot(FVector FireDirection);
	

	/* Handler for the fire timer expiry */
	void ShotTimerExpired();

	

	//Recargar energia
	void ReloadEnergy();

	//Saber el numero de inventario
	void CheckInventory();

	void OnSpawnActor();

	void ActivarDisparoDoble();	
	void RepeatMovement();
	void RecordMovement();
	

	// Static names for axis bindings
	static const FName MoveForwardBinding;
	static const FName MoveRightBinding;
	//static const FName MoveDiagonalBinding;
	static const FName FireForwardBinding;
	static const FName FireRightBinding;

private:

	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	int32 NumProyectilesDisparados;
	int32 MaxProyectilesDisparados;
	//int32 NumItems;
	FVector InicialPosicion;
	float AlturaSalto;
	FVector2D lastInput;

	//Banderas
	bool bDisparoDoble;
	

public:
	/** Returns ShipMeshComponent subobject **/
	FORCEINLINE class UStaticMeshComponent* GetShipMeshComponent() const { return ShipMeshComponent; }
	/** Returns CameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

protected:
	
	//Referencia al sonido de la m�sica de fondo
	UPROPERTY(EditAnywhere, Category ="Sound") // EditAnywhere permite modificar el valor de la variable en el editor
	class USoundBase* Music; 

public:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UActorSpawnerComponent* ActorSpawnerComponent;

};

