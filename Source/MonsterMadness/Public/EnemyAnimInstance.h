// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnemyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERMADNESS_API UEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
protected:
	/** True if is air of falling */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bIsFalling;

	/** Holds a reference to character's movement speed */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MovementSpeed;

	/** Updates the Movement Speed variable */
	UFUNCTION(BlueprintCallable, Category = EnemyAnimationUpdates)
	void UpdateAnimationProperties();

public:
	/** TODO implement AI Enemy Attack */
	UFUNCTION()
	void Attack();	
	
	
};
