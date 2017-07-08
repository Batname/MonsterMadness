// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "EnemyAIController.h"
#include "Perception/PawnSensingComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	// Init Pawn sensing component
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(90.f);

	// Init life text component
	EnemyLifeText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("EnemyLifeText"));
	EnemyLifeText->TextRenderColor = FColor(255, 0, 0, 1);
	EnemyLifeText->SetupAttachment(RootComponent);
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

	// Init health
	InitHealth();
}

void AEnemyCharacter::OnSeePlayer(APawn* Pawn)
{
	AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(GetController());

	// Set the seen target on the blackbord
	if (EnemyAIController != nullptr)
	{
		EnemyAIController->SetSeenTarget(Pawn);
	}
}

void AEnemyCharacter::InitHealth()
{
	Health = MaxHealth;
	UpdateEnemyLifeText();
}

void AEnemyCharacter::UpdateEnemyLifeText()
{
	FString NewText = FString("Health: ") + FString::SanitizeFloat(Health);

	// Set the created string to next render component
	EnemyLifeText->SetText(FText::FromString(NewText));
}

float AEnemyCharacter::SimpleDamage(float Damage)
{
	Health -= Damage;
	UpdateEnemyLifeText();

	if (Health <= 0 )
	{
		Die();
	}

	return Health;
}

float AEnemyCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	return SimpleDamage(Damage);
}

void AEnemyCharacter::Die()
{

	AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(GetController());
	EnemyAIController->StopLogic();

	USkeletalMeshComponent* CharSM = GetMesh();
	CharSM->AddRadialImpulse(GetActorLocation(), 5000.0f, 1000.0f, ERadialImpulseFalloff::RIF_Linear, true);
	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->SetAllBodiesSimulatePhysics(true);
	GetMesh()->WakeAllRigidBodies();
	CharSM->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);

	FTimerHandle TimerHandle;
	FTimerDelegate TimerDel;

	TimerDel.BindLambda([&]()
	{
		Destroy();
	});

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDel, 1.5f, false);
}