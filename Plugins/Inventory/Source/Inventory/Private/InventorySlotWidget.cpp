// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlotWidget.h"
#include "Pickup.h"

#include "Engine/Texture2D.h"

void UInventorySlotWidget::SetItemTexture(APickup* Item)
{
	if (Item != nullptr)
	{
		ItemTexture = Item->GetPickupTexture();
	}
	else
	{
		ItemTexture = nullptr;
	}
}