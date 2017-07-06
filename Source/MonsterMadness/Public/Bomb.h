// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomb.generated.h"

UCLASS()
class MONSTERMADNESS_API ABomb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomb();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	/** This is static mesh of the comp */
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* SM;

	/** The projectile movement component */
	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* ProjectileMovementComp;

	/** Sphere comp used for colision. Movement component need a collision as root function properly */
	UPROPERTY(VisibleAnywhere)
	class USphereComponent* SphereComp;

	/** The delay unit explotion */
	UPROPERTY(EditAnywhere, Category = BombProps)
	float FuseTime = 2.5f;

	UPROPERTY(EditAnywhere, Category = BombProps)
	float ExplosionRadius = 200.f;

	UPROPERTY(EditAnywhere, Category = BombProps)
	float ExplosionDamage = 25.f;

	/** The parricle system of the explosion */
	UPROPERTY(EditAnywhere, Category = BombProps)
	class UParticleSystem* ExplosionFX;

private:
	/** Arms the bomb for explosion */
	void ArmBomb();

	/** Called when our bomb bounces */
	UFUNCTION()
	void OnProjectileBounce(const FHitResult& ImpactResult, const FVector& ImpactVelocity);

	/** Performs an Explosion after a centain amount of time */
	void PerformDelayedExplosion(float ExplosionDelay);

	/** Performs as explosion when called */
	UFUNCTION()
	void Explode();
};
