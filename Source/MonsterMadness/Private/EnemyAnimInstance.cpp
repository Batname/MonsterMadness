// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAnimInstance.h"
#include "EnemyCharacter.h"
#include "GameFramework/PawnMovementComponent.h"


void UEnemyAnimInstance::UpdateAnimationProperties()
{
	// Try to cast valid Pawn
	APawn* Pawn = TryGetPawnOwner();

	if (Pawn != nullptr)
	{
		bIsFalling = Pawn->GetMovementComponent()->IsFalling();

		MovementSpeed = Pawn->GetVelocity().Size();

		// Try to cast our enemy
		AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(Pawn);

		if (EnemyCharacter)
		{
			bIsAttack = EnemyCharacter->GetIsAttack();
			if (bIsAttack)
			{
				PlayAttack();
			}
		}
	}
}

void UEnemyAnimInstance::PlayAttack()
{
	if (AttackMontage != nullptr)
	{
		FName CurrentSection = Montage_GetCurrentSection(AttackMontage);

		if (CurrentSection.IsNone())
		{
			Montage_Play(AttackMontage);
		}
		else if (CurrentSection.IsEqual("EnemyAttackStart") && bIsAttack)
		{
			Montage_JumpToSection(FName("EnemyAttackMain"), AttackMontage);
		}
	}
}