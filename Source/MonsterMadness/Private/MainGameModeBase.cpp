// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameModeBase.h"
#include "EnemySpawnVolume.h"
#include "EnemyAIController.h"
#include "PlayerCharacter.h"
#include "PlayerHUD.h"
#include "EnemyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkeletalMeshComponent.h"

void AMainGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = GetWorld()->GetFirstPlayerController();

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemySpawnVolume::StaticClass(), FoundActors);

	for (auto Actor : FoundActors)
	{
		EnemySpawnVolume = Cast<AEnemySpawnVolume>(Actor);

		if (EnemySpawnVolume)
		{
			EnemySpawnVolume->SetSpawningActive(true);
		}
	}
}

void AMainGameModeBase::PlayerDie()
{
	ACharacter* Character = UGameplayStatics::GetPlayerCharacter(this, 0);

	if (PlayerController != nullptr)
	{
		// Block player input
		PlayerController->SetCinematicMode(true, false, false, true, true);
		if (Character != nullptr)
		{
			Character->DisableInput(PlayerController);
		}
	}

	if (Character != nullptr)
	{
		USkeletalMeshComponent* CharSM = Character->GetMesh();
		CharSM->SetSimulatePhysics(true);
		CharSM->SetAllBodiesSimulatePhysics(true);
		CharSM->WakeAllRigidBodies();
		CharSM->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);

		APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(Character);

		if (PlayerCharacter)
		{
			PlayerCharacter->bIsAlive = false;
		}
	}

	// Stop spawning
	if (EnemySpawnVolume != nullptr)
	{
		EnemySpawnVolume->SetSpawningActive(false);
	}

	// Stop all AI movement
	for (auto EnemyCharacter : EnemyCharacters)
	{
		// Stop logic of AI
		AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(EnemyCharacter->GetController());
		if (EnemyAIController != nullptr)
		{
			EnemyAIController->StopLogic();
		}
	}


	FTimerHandle TimerHandle;
	FTimerDelegate TimerDel;

	TimerDel.BindLambda([&]()
	{
		APlayerHUD* PlayerHUD = Cast<APlayerHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());

		if (PlayerHUD != nullptr)
		{
			PlayerController->bShowMouseCursor = true;
			PlayerHUD->AddRestartWidget();
		}
	});

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDel, 1.5f, false);
}

