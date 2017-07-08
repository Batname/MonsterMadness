// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstance.h"
#include "GameFramework/PawnMovementComponent.h"
#include "PlayerCharacter.h"


void UPlayerAnimInstance::UpdateAnimationProperties()
{
	APawn* Pawn = TryGetPawnOwner();

	if (Pawn != nullptr)
	{
		bIsFalling = Pawn->GetMovementComponent()->IsFalling();

		MovementSpeed = Pawn->GetVelocity().Size();

		// Try to cast our player
		APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(Pawn);

		if (PlayerCharacter)
		{
			bIsSlashing = PlayerCharacter->GetIsSlashing();

			if (bIsSlashing)
			{
				PlaySlash();
			}
		}
	}
}

void UPlayerAnimInstance::PlaySlash()
{
	if (SlashMontage != nullptr)
	{
		FName CurrentSection = Montage_GetCurrentSection(SlashMontage);

		if (CurrentSection.IsNone())
		{
			Montage_Play(SlashMontage);
		}
		else if (CurrentSection.IsEqual("StartSlash") && bIsSlashing)
		{
			Montage_JumpToSection(FName("SlashMain"), SlashMontage);
		}
	}
}