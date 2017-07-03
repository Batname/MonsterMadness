// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MenuPlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERMADNESSMENU_API UMenuPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	/** Holds a reference to the character's movement speed */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MovementSpeed;

	/** The attack montage */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAnimMontage* MeleeAttackMontage;

	/** Updates movement speed */
	UFUNCTION(BlueprintCallable, Category = MenuPlayerAnimation)
	void UpdateMovementSpeed();

	/** True if teh character can perform second attack */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bAcceptsSecondAttackInput;

	/** True if the cahracter can perform a third attack */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bAcceptsThirdAttackInput;

	/** The idle sword montage */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAnimMontage* IdleSwordMontage;

public:
	/** Determinates which attack animaiton will be played */
	void Attack();
	void RunIdleSwordMontage();
};
