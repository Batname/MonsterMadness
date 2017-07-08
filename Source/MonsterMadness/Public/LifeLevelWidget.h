// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LifeLevelWidget.generated.h"


USTRUCT()
struct FPlayerLifeStruct
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float MaxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Health;
};

/**
 * 
 */
UCLASS()
class MONSTERMADNESS_API ULifeLevelWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = PlayerHealth)
	FPlayerLifeStruct GetPlayerLifeStruct();
	
};
