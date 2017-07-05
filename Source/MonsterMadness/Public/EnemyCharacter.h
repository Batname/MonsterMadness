// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class MONSTERMADNESS_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	/** AI behavior when seen the player */
	UFUNCTION()
	void OnSeePlayer(APawn* Pawn);

	/** The Component which is used for the "seeing" sense of the AI */
	UPROPERTY(VisibleAnywhere, Category = EnemyAI)
	class UPawnSensingComponent* PawnSensingComp;

	/** The behavior tree of the Character */
	UPROPERTY(EditAnywhere, Category = EnemyAI)
	class UBehaviorTree* BehaviorTree;
};