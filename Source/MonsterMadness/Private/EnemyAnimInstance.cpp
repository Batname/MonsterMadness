// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAnimInstance.h"

void UEnemyAnimInstance::UpdateMovementSpeed()
{
	// Try to cast valid Pawn
	APawn* Pawn = TryGetPawnOwner();

	if (Pawn != nullptr)
	{
		MovementSpeed = Pawn->GetVelocity().Size();
	}
}


// TODO implement AI Enemy Attack 
void UEnemyAnimInstance::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("UEnemyAnimInstance::Attack"));
}