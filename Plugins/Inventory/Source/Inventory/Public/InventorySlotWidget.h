// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventorySlotWidget.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UInventorySlotWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	/** Holds the reference to the item texture */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UTexture2D* ItemTexture;

public:
	/** Sets the Item Texture */
	UFUNCTION(BlueprintCallable, Category = InventoryUI)
	void SetItemTexture(class APickup* Item);
	
};
