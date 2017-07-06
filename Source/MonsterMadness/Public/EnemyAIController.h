// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERMADNESS_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	/** Behavior tree component reference */
	class UBehaviorTreeComponent* BehaviorComp;

	class UBrainComponent* BrainComponent;

	/** Black board comp reference */
	class UBlackboardComponent* BlackboardComp;
	
public:
	/** Constructor */
	AEnemyAIController();

	/** Blackboard key */
	UPROPERTY(EditDefaultsOnly, Category = EnemyAI)
	FName BlackboardKey = "Target";

	/** Execute right when the controller possess a Pawn */
	virtual void Possess(APawn* Pawn) override;

	/** Set the sensed target in the blackboard */
	UFUNCTION()
	void SetSeenTarget(class APawn* PlayerPawn);

	void StopLogic();
};
