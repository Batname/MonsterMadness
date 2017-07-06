// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameModeBase.h"
#include "EnemySpawnVolume.h"
#include "Kismet/GameplayStatics.h"

void AMainGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemySpawnVolume::StaticClass(), FoundActors);

	for (auto Actor : FoundActors)
	{
		AEnemySpawnVolume* EnemySpawnVolume = Cast<AEnemySpawnVolume>(Actor);

		if (EnemySpawnVolume)
		{
			EnemySpawnVolume->SetSpawningActive(true);
		}
	}
}

