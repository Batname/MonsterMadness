// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "LifeLevelWidget.h"

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	// Add LifeLevelWidget
	if (BP_LifeLevelWidget != nullptr)
	{
		// Create and add to view port
		LifeLevelWidget = CreateWidget<ULifeLevelWidget>(this->GetOwningPlayerController(), BP_LifeLevelWidget);
		LifeLevelWidget->AddToViewport();
	}
}

void APlayerHUD::DrawHUD()
{
	Super::DrawHUD();
}