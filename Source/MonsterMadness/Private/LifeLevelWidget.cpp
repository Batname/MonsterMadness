// Fill out your copyright notice in the Description page of Project Settings.


#include "LifeLevelWidget.h"
#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"

FPlayerLifeStruct ULifeLevelWidget::GetPlayerLifeStruct()
{
	struct FPlayerLifeStruct PlayerLifeStruct;
	PlayerLifeStruct.Health = 0.0f;
	PlayerLifeStruct.MaxHealth = 0.0f;

	ACharacter* Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	if (Character != nullptr)
	{
		APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(Character);
		if (PlayerCharacter != nullptr)
		{
			PlayerLifeStruct.Health = PlayerCharacter->GetHealth();
			PlayerLifeStruct.MaxHealth = PlayerCharacter->GetMaxHealth();
			return PlayerLifeStruct;
		}
	}

	return PlayerLifeStruct;
}
