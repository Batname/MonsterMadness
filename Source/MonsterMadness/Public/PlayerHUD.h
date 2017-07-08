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
	
protected:
	/** LifeLevel blueprint reference */
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ULifeLevelWidget> BP_LifeLevelWidget;

	/** RestartGameWidget blueprint reference */
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class URestartGameWidget> BP_RestartGameWidget;

public:
	virtual void BeginPlay() override;
	virtual void DrawHUD() override;


	/** Draw restart widget */
	UFUNCTION()
	void AddRestartWidget();
};
