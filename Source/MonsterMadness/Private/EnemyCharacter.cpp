// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"


// Sets default values
AEnemyCharacter::AEnemyCharacter()
{

	// Init Pawn sensing component
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(90.f);
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Register the funciton that is going to fire when the character seen a Pawn
	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AEnemyCharacter::OnSeePlayer);
	}
	
}

void AEnemyCharacter::OnSeePlayer(APawn* Pawn)
{
	AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(GetController());

	// Set the seen target on the blackbord
	if (EnemyAIController != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hello player from Enemy"));
		EnemyAIController->SetSeenTarget(Pawn);
	}
}