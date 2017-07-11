// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERMADNESS_API APlayerHUD : public AHUD
{
	GENERATED_BODY()
	
private:
	/** Life level cpp class reference */
	class ULifeLevelWidget* LifeLevelWidget;	

	/** RestartGameWidget cpp class reference */
	class URestartGameWidget* RestartGameWidget;

	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;
	
protected:
	/** LifeLevel blueprint reference */
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ULifeLevelWidget> BP_LifeLevelWidget;

	/** RestartGameWidget blueprint reference */
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class URestartGameWidget> BP_RestartGameWidget;

public:
	APlayerHUD();


	virtual void BeginPlay() override;
	virtual void DrawHUD() override;


	/** Draw restart widget */
	UFUNCTION()
	void AddRestartWidget();

private:
	/** Hold ref to character */
	class APlayerCharacter* PlayerCharacter;


	/** Hold ref to Controller */
	class AMainPlayerController* MainPlayerController;

// ------------ Inventory system
// ---------------------------

private:
	/** reference to widget */
	class UInventoryWidget* InventoryWidget;

	/** True if inventory is currently open - false otherwise */
	bool bIsInventoryOpen;

protected:
	/** Inventorywidget blueprint reference */
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UInventoryWidget> BP_InventoryWidget;

public:

	/** Open or close the inventory */
	void HandleInventoryInput();
};
