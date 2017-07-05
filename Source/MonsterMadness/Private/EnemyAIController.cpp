// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "EnemyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"


AEnemyAIController::AEnemyAIController()
{
	// Initialize the behaviour tree components
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
}

void AEnemyAIController::Possess(APawn* Pawn)
{
	Super::Possess(Pawn);

	// Cast enemy character
	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(Pawn);

	if (EnemyCharacter != nullptr)
	{
		UBlackboardData* EnemyBlackboardAsset = EnemyCharacter->BehaviorTree->BlackboardAsset;

		if (EnemyBlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*EnemyBlackboardAsset);
			BehaviorComp->StartTree(*EnemyCharacter->BehaviorTree);
		}
	}
}

void AEnemyAIController::SetSeenTarget(APawn* PlayerPawn)
{
	// Register the Pawn that the AI has Seen in the Blackboard
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(BlackboardKey, PlayerPawn);
	}
}