// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BI_SlotUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class BATINVENTORY_API UBI_SlotUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	/** Holds the reference to the item texture */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UTexture2D* ItemTexture;

public:
	/** Sets the Item Texture */
	UFUNCTION(BlueprintCallable, Category = InventoryUI)
	void SetItemTexture(class ABI_Pickup* Item);
	
};
