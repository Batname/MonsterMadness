// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "LifeLevelWidget.h"
#include "RestartGameWidget.h"
#include "Kismet/GameplayStatics.h"

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

void APlayerHUD::AddRestartWidget()
{
	if (BP_RestartGameWidget != nullptr)
	{
		// Create and add to view port
		RestartGameWidget = CreateWidget<URestartGameWidget>(this->GetOwningPlayerController(), BP_RestartGameWidget);
		RestartGameWidget->AddToViewport();
	}
}