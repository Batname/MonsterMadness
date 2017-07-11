// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "LifeLevelWidget.h"
#include "RestartGameWidget.h"
#include "PlayerCharacter.h"
#include "MainPlayerController.h"

// Plagins
#include "InventoryWidget.h"

// Engine
#include "Engine/Canvas.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Texture2D.h"
#include "UObject/ConstructorHelpers.h"


APlayerHUD::APlayerHUD()
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;
}

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	// Set reference to controller
	MainPlayerController = Cast<AMainPlayerController>(this->GetOwningPlayerController());

	// set reference to character
	PlayerCharacter = Cast<APlayerCharacter>(MainPlayerController->GetPawn());

	// Add LifeLevelWidget
	if (BP_LifeLevelWidget != nullptr)
	{
		// Create and add to view port
		LifeLevelWidget = CreateWidget<ULifeLevelWidget>(MainPlayerController, BP_LifeLevelWidget);
		LifeLevelWidget->AddToViewport();
	}

	// Init Inventory widget
	if (BP_InventoryWidget != nullptr)
	{
		InventoryWidget = CreateWidget<UInventoryWidget>(MainPlayerController, BP_InventoryWidget);
	}

	bIsInventoryOpen = false;
}

void APlayerHUD::DrawHUD()
{
	Super::DrawHUD();

	// Find center of canvas
	const FVector2D Center(Canvas->ClipX * 0.5, Canvas->ClipY * 0.5f);

	// Offset by halv the texture
	const FVector2D CrosshairDrawPosition((Center.X), (Center.Y + 20.f));

	// Draw crosshair
	FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}

void APlayerHUD::AddRestartWidget()
{
	if (BP_RestartGameWidget != nullptr)
	{
		// Create and add to view port
		RestartGameWidget = CreateWidget<URestartGameWidget>(MainPlayerController, BP_RestartGameWidget);
		RestartGameWidget->AddToViewport();
	}
}

// ------------ Inventory system
// ---------------------------

void APlayerHUD::HandleInventoryInput()
{

	if (!InventoryWidget)
	{
		return;
	}

	if (bIsInventoryOpen)
	{
		// Mark Inventory as closed
		bIsInventoryOpen = false;

		// Remove from viewpost
		InventoryWidget->RemoveFromViewport();

		// Hide the cursor of our game
		MainPlayerController->bShowMouseCursor = false;

		// Tell the game we want to register inputsa for our game only and not for our UI
		FInputModeGameOnly InputMode;
		MainPlayerController->SetInputMode(InputMode);

		// Unpause the game
		MainPlayerController->SetPause(false);
	}
	else
	{
		// Mark Inventory as open
		bIsInventoryOpen = true;

		if (PlayerCharacter != nullptr)
		{
			// re-populate Items Array
			InventoryWidget->ItemsArray = PlayerCharacter->GetInventory();
		}

		InventoryWidget->Show();


		// Show the cursor of our game
		MainPlayerController->bShowMouseCursor = true;

		// Tell the game we want to register inputsa for our game only and not for our UI
		FInputModeGameAndUI InputMode;
		MainPlayerController->SetInputMode(InputMode);

		// Unpause the game
		MainPlayerController->SetPause(true);
	}
}