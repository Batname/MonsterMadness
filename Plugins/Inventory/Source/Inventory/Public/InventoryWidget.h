// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	/** Adds the widget into the viewport and populates teh inventory */
	UFUNCTION(BlueprintImplementableEvent, Category = InventoryUI)
	void Show();

	/** Removes widget from viewport */
	UFUNCTION(BlueprintImplementableEvent, Category = InventoryUI)
	void Hide();

	/** Stores a refewrence in order to bind information on inventory slots */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<class APickup*> ItemsArray;
};
