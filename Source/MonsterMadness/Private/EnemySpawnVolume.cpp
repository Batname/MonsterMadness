// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawnVolume.h"
#include "EnemyCharacter.h"
#include "PlayerCharacter.h"
#include "MainGameModeBase.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AEnemySpawnVolume::AEnemySpawnVolume()
{
	// Create box component
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;

	// Set spawn delay
	SpawnDelayRangeLow = 1.f;
	SpawnDelayRangeHigh = 2.5f;

	// Spawn enemies count
	SpawnCount = 6;

}

// Called when the game starts or when spawned
void AEnemySpawnVolume::BeginPlay()
{
	Super::BeginPlay();

	MainGameModeBase = Cast<AMainGameModeBase>(GetWorld()->GetAuthGameMode());
}


FVector AEnemySpawnVolume::GetRandomPointInVolume()
{
	FVector SpawnOrigin = WhereToSpawn->Bounds.Origin;
	FVector SpawnExtend = WhereToSpawn->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtend);
}

void AEnemySpawnVolume::SetSpawningActive(bool bShouldSpawn)
{

	if (bShouldSpawn)
	{
		// Set the timer on Spawn pickup
		SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
		GetWorldTimerManager().SetTimer(SpawnTimer, this, &AEnemySpawnVolume::SpawnEnemy, SpawnDelay, false);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(SpawnTimer);
	}
}

void AEnemySpawnVolume::SpawnEnemy()
{
	// Clear timeout and exit if we get max spawned enemies
	if (CurrentSpawn == SpawnCount)
	{
		GetWorldTimerManager().ClearTimer(SpawnTimer);
		return;
	}

	// If we setup spawn in blueprint
	if (BP_EnemyCharacter != nullptr)
	{
		// Chack for valid world
		UWorld* World = GetWorld();

		if (World != nullptr)
		{
			// Set Spawn parameters
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			// GetEandom location to Spawn
			FVector SpawnLocation = GetRandomPointInVolume();

			// Get player Location
			ACharacter* Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
			FVector CharacterLocation = Character->GetActorLocation();

			// Get a random rotation
			FRotator SpawnRotation;
			SpawnRotation.Yaw = (CharacterLocation - SpawnLocation).Rotation().Yaw;
			SpawnRotation.Pitch = 0.f;
			SpawnRotation.Roll = 0.f;

			// Spawn an Enemy
			ACharacter* EnemyCharacter = World->SpawnActor<AEnemyCharacter>(BP_EnemyCharacter, SpawnLocation, SpawnRotation, SpawnParams);

			SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &AEnemySpawnVolume::SpawnEnemy, SpawnDelay, false);

			// Add reference to game mode array
			if (MainGameModeBase != nullptr)
			{
				MainGameModeBase->GetEnemyCharacters().AddUnique(EnemyCharacter);
			}

			// Increase counter
			CurrentSpawn++;
		}
	}
}