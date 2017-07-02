// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERMADNESSMENU_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	/** Load first level */
	UFUNCTION(BlueprintCallable, Category = MainMenu)
	void LoadFirstLevel();

	/** Load first level */
	UFUNCTION(BlueprintCallable, Category = MainMenu)
	void QuitGame();
	
};
