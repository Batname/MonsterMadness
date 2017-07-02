// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"
#include "MenuWidget.h"

void AMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (BP_MenuWidget)
	{
		// Create menu widget and add to view port
		MenuWidget = CreateWidget<UMenuWidget>(this, BP_MenuWidget);
		MenuWidget->AddToViewport();
	}
}