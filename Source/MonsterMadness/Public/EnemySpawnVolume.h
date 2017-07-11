// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawnVolume.generated.h"

UCLASS()
class MONSTERMADNESS_API AEnemySpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	/** Returns where to spawn component */
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	/** Return random vector in volume */
	UFUNCTION(BlueprintCallable, Category = EnemySpawning)
	FVector GetRandomPointInVolume();

	/** Toggle enemies spawning */
	UFUNCTION(BlueprintCallable, Category = EnemySpawning)
	void SetSpawningActive(bool bShouldSpawn);

protected:
	/** The enemy to spawn */
	UPROPERTY(EditAnywhere, Category = EnemySpawning)
	TSubclassOf<class AEnemyCharacter> BP_EnemyCharacter;

	/** Spawning timer */
	FTimerHandle SpawnTimer;

	/** Min spawn deley */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EnemySpawning)
	float SpawnDelayRangeLow;

	/** Max spwn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EnemySpawning)
	float SpawnDelayRangeHigh;

	/** Enamies spawn count */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EnemySpawning)
	uint8 SpawnCount;


private:
	/** Box component to specify where enemies should be spawned */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = EnemySpawning, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;

	/** Handle spawning a new Enemy */
	void SpawnEnemy();

	/** The current spawn delay */
	float SpawnDelay;

	/** The current spawned enemy */
	uint8 CurrentSpawn = 0;

	class AMainGameModeBase* MainGameModeBase;

	/** Begin overlap event */
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** End Ovelrap event */
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	/** Additon overlap player check variable */
	bool bIsPlayerInside = false;
};
