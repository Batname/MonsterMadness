// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory.h"
#include "Trader.h"


// Sets default values
ATrader::ATrader()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATrader::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATrader::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

