// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAnimInstance.h"
#include "GameFramework/PawnMovementComponent.h"


void UEnemyAnimInstance::UpdateAnimationProperties()
{
	// Try to cast valid Pawn
	APawn* Pawn = TryGetPawnOwner();

	if (Pawn != nullptr)
	{
		bIsFalling = Pawn->GetMovementComponent()->IsFalling();

		MovementSpeed = Pawn->GetVelocity().Size();
	}
}


// TODO implement AI Enemy Attack 
void UEnemyAnimInstance::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("UEnemyAnimInstance::Attack"));
}