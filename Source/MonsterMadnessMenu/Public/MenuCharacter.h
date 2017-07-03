// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MenuCharacter.generated.h"

UCLASS()
class MONSTERMADNESSMENU_API AMenuCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMenuCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void Attack();

	UFUNCTION()
	void RunIdleSwordMontage();

	UPROPERTY()
	class UMenuPlayerAnimInstance* AnimInstanceRef;
	
protected:

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* ThirdPersonSpringArmComp;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* ThirdPersonCameraComp;
};
