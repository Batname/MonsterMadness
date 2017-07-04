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
	UPROPERTY()
	class ULifeLevelWidget* LifeLevelWidget;
	
protected:
	/** LifeLevel blueprint reference */
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ULifeLevelWidget> BP_LifeLevelWidget;

public:
	virtual void BeginPlay() override;
	virtual void DrawHUD() override;
};
