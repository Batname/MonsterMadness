// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class INVENTORY_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** The Static mesh of the pickup */
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* PickupSM;

	/** The texture of the item in case we want to add it in the inventory */
	UPROPERTY(EditAnywhere, Category = PickupProperties)
	class UTexture2D* PickupTexture;

	/** Name of the Item */
	UPROPERTY(EditAnywhere, Category = PickupProperties)
	FString ItemName;

public:

	/** Enable/Disable the glow effect on the pickup */
	UFUNCTION()
	void SetGlowEffect(bool Status);

	/** Returns the Texture of our pickup */
	FORCEINLINE class UTexture2D* GetPickupTexture() { return PickupTexture; }
	
	
};
