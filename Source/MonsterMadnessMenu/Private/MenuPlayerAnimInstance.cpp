// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerAnimInstance.h"

void UMenuPlayerAnimInstance::UpdateMovementSpeed()
{
	APawn* Pawn = TryGetPawnOwner();

	if (Pawn)
	{
		MovementSpeed = Pawn->GetVelocity().Size();
	}
}

void UMenuPlayerAnimInstance::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("UMenuPlayerAnimInstance::Attack"));
}