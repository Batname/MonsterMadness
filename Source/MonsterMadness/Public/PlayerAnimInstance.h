// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERMADNESS_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	
protected:
	/** True means that we're currently in air - or falling */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bIsFalling;

	/** Holds the current speed of our character */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MovementSpeed;

	/** Updates the above parameters */
	UFUNCTION(BlueprintCallable, Category = UpdateAnimationProperties)
	void UpdateAnimationProperties();
};
