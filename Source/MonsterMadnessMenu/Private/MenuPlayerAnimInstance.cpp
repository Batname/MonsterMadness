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
	if (MeleeAttackMontage)
	{
		FName CurrentSection = Montage_GetCurrentSection(MeleeAttackMontage);

		if (CurrentSection.IsNone())
		{
			// For now all the time is true
			Montage_Play(MeleeAttackMontage);
		}
	}
}

void UMenuPlayerAnimInstance::RunIdleSwordMontage()
{
	if (IdleSwordMontage)
	{
		// For now all the time is true
		Montage_Play(IdleSwordMontage);
	}
}