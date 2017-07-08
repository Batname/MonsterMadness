// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RestartGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERMADNESS_API URestartGameWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	/** Go to main menu button click */
	UFUNCTION(BlueprintCallable, Category = RestartGame)
	void GoToMainMenu();

	/** Restart level button click */
	UFUNCTION(BlueprintCallable, Category = RestartGame)
	void RestartLevel();

	/** Quit game button click */
	UFUNCTION(BlueprintCallable, Category = RestartGame)
	void QuitGame();
};
