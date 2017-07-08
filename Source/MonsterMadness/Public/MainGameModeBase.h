// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERMADNESS_API AMainGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	/** Store Spawn volume reference */
	UPROPERTY()
	class AEnemySpawnVolume* EnemySpawnVolume;
	
public:

	virtual void BeginPlay() override;
	
	/** Kill the player */
	UFUNCTION()
	void PlayerDie();

	TArray<class ACharacter*>& GetEnemyCharacters() { return EnemyCharacters; }

private:

	/** Store reference to Player Controller */
	class APlayerController* PlayerController;

	/** Collect all enemies */
	UPROPERTY()
	TArray<class ACharacter*> EnemyCharacters;
};
