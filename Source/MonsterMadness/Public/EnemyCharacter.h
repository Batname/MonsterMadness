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

	virtual void Tick(float DeltaSeconds) override;

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

protected:
	/** The health of the character */
	UPROPERTY(VisibleAnywhere, Category = EnemyAI)
	float Health;

	/** The max health  of the enemy */
	UPROPERTY(EditAnywhere, Category = EnemyAI)
	float MaxHealth = 100.f;

	/** Text render compnent - show enemy life */
	UPROPERTY(VisibleAnywhere)
	class UTextRenderComponent* EnemyLifeText;

private:
	/** Initalizes health */
	UFUNCTION()
	void InitHealth();

	/** Update enemy text */
	UFUNCTION()
	void UpdateEnemyLifeText();

	UFUNCTION()
	void Die();

public:
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	float SimpleDamage(float Damage);

	UFUNCTION()
	bool GetIsAttack() const { return bIsAttack; }

// ---- Enamy Raycast
protected:
	/** The Height of my Sphere starting form location of enemy */
	UPROPERTY(EditAnywhere, Category = EnamyRaycast)
	float SphereHeight = 200.f;

	/** Radious the sphere trace */
	UPROPERTY(EditAnywhere, Category = EnamyRaycast)
	float SphereRadius = 500.f;

	/** Sphere sigment, ony for debugging */
	UPROPERTY(EditAnywhere, Category = EnamyRaycast)
	float SphereSegments = 100.f;

protected:
	/** Attach Collision Sphere */
	UPROPERTY(EditAnywhere, Category = EnamyAttack)
	class UShapeComponent* AttackHandsSphereComp;

	/** Set Attack status */
	UPROPERTY()
	bool bIsAttack = false;

	/** Distance for attack */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttackDistance = 180.f;

	/** Max Rate of damage */
	UPROPERTY(EditAnywhere, Category = Stats)
	int32 MaxEnemyDamageRate = 15.f;

	/** Min Rate of damage */
	UPROPERTY(EditAnywhere, Category = Stats)
	int32 MinEnemyDamageRate = 3.f;

private:
	UFUNCTION()
	void OnBeginAttackSphereOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	class APlayerCharacter* PlayerCharacter;

	/** Game mode reference */
	UPROPERTY()
	class AMainGameModeBase* MainGameModeBase = nullptr;
};
