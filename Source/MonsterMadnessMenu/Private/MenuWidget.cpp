// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"
#include "Kismet/GameplayStatics.h"

void UMenuWidget::LoadFirstLevel()
{
	UGameplayStatics::OpenLevel(GetWorld(), "FirstLevel");
}

void UMenuWidget::QuitGame()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}
