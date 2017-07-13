// Fill out your copyright notice in the Description page of Project Settings.


#include "BI_SlotUserWidget.h"
#include "BI_Pickup.h"

#include "Engine/Texture2D.h"

void UBI_SlotUserWidget::SetItemTexture(ABI_Pickup* Item)
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



