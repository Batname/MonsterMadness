// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

#define MAX_INVENTORY_ITEMS 4

UCLASS(config=Game)
class MONSTERMADNESS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Bomb Blueprint */
	UPROPERTY(EditAnywhere, Category = BombProps)
	TSubclassOf<class ABomb> BP_Bomb;

	/** Sword Collision Sphere */
	UPROPERTY(EditAnywhere, Category = Slash)
	class UShapeComponent* SwordCollisionComp;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
private:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	/** Base turn rate, in deg/sec. Other scaling may affected final result */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	UFUNCTION(BlueprintCallable)
	bool GetIsSlashing() { return bIsSlashing; }

protected:
	/** Called forward/backward input */
	void MoveForward(float Value);

	/** Called slide to slide input */
	void MoveRight(float Value);

	/** Called when left mouse pressed */
	void SlashStart();

	/** Called when left mouse released */
	void SlashEnd();

	/**
	 * Called via input to turn at a given time
	 * @param Rate This is normalized rate, 1.0
	 */
	void TurnAtRate(float Rate);

	/** Escape game input action */
	void EscapeGameInput();

	/** Number of player bombs */
	UPROPERTY(VisibleAnywhere, Category = Stats)
	int32 BombCount;

	/** The max bomb of the character */
	UPROPERTY(EditAnywhere, Category = Stats)
	int32 MaxBombCount = 30;

	/** Max Rate of sword damage */
	UPROPERTY(EditAnywhere, Category = Stats)
	int32 MaxSwordDamageRate = 15.f;

	/** Min Rate of sword damage */
	UPROPERTY(EditAnywhere, Category = Stats)
	int32 MinSwordDamageRate = 3.f;

	/** The health of the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = PlayerHealth)
	float Health;

	/** The max health  of the enemy */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerHealth)
	float MaxHealth = 500.f;

private:
	/** Set Movement Input */
	void MovementInput(float Value, EAxis::Type Axis);

	/** Will try to spawn bomb */
	UFUNCTION()
	void AttempToSpawnBomb();

	/** If any bombs left */
	bool HasBombs() { return BombCount > 0; }

	/** Is now Slashing */
	UPROPERTY()
	bool bIsSlashing = false;

	UFUNCTION()
	void OnBeginSwordOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** Handle player Die status */
	UFUNCTION()
	void Die();

public:

	UFUNCTION(BlueprintPure, Category = PlayerHealth)
	float GetHealth() const { return Health; }

	UFUNCTION(BlueprintPure, Category = PlayerHealth)
	float GetMaxHealth() const { return MaxHealth; }

	UFUNCTION()
	float SimpleDamage(float Damage);

	UPROPERTY()
	bool bIsAlive = true;

private:
	/** Hold Contoller reference */
	class AMainPlayerController* MainPlayerController;

	/** Hold HUD reference */
	class APlayerHUD* PlayerHUD;

// ------------ Inventory system
// ---------------------------

private:
	/** Raycast in front of the character to find usable items */
	UFUNCTION()
	void Raycast();

	/** Reference to the last seen pickup Item. */
	class APickup* LastItemSeen;


protected:
	/* The Renge of the raycast */
	UPROPERTY(EditAnywhere)
	float RaycastRange = 250.f;

	/** Handle pickup input */
	UFUNCTION()
	void PickupItem();

	/** Player inventory */
	UPROPERTY(VisibleAnywhere)
	TArray<class APickup*> Inventory;

	/** handles the inventory inpuyt from the user */
	UFUNCTION()
	void HandleInventoryInput();

public:
	TArray<class APickup*> GetInventory() { return Inventory; }


private:
	/** Reference to the currently quipped item */
	class APickup* CurrentlyEquippedItem;


public:
	/** Set a new equipeed item based on given texture */
	UFUNCTION(BlueprintCallable, Category = InventoryUI)
	void SetEquippedItem(class UTexture2D* Texture);

private:
	/** Drops the curently Equipped item */
	UFUNCTION()
	void DropEquippedItem();
};
