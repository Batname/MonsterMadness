// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

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

protected:
	/** Called forward/backward input */
	void MoveForward(float Value);

	/** Called slide to slide input */
	void MoveRight(float Value);

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

private:
	/** Set Movement Input */
	void MovementInput(float Value, EAxis::Type Axis);

	/** Will try to spawn bomb */
	UFUNCTION()
	void AttempToSpawnBomb();

	/** If any bombs left */
	bool HasBombs() { return BombCount > 0; }
};
