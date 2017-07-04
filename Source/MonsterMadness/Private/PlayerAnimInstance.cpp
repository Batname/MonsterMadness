// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstance.h"
#include "GameFramework/PawnMovementComponent.h"


void UPlayerAnimInstance::UpdateAnimationProperties()
{
	APawn* Pawn = TryGetPawnOwner();

	if (Pawn != nullptr)
	{
		bIsFalling = Pawn->GetMovementComponent()->IsFalling();

		MovementSpeed = Pawn->GetVelocity().Size();
	}
}

