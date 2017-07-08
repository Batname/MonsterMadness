// Fill out your copyright notice in the Description page of Project Settings.


#include "RestartGameWidget.h"
#include "Kismet/GameplayStatics.h"



void URestartGameWidget::GoToMainMenu()
{
	UGameplayStatics::OpenLevel(GetWorld(), "MenuLevel");
}

void URestartGameWidget::RestartLevel()
{
	UGameplayStatics::OpenLevel(GetWorld(), "FirstLevel");
}

void URestartGameWidget::QuitGame()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}