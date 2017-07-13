// Fill out your copyright notice in the Description page of Project Settings.


#include "BI_Pickup.h"

#include "Components/StaticMeshComponent.h"
#include "Engine/Texture2D.h"


// Sets default values
ABI_Pickup::ABI_Pickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Init properties
	PickupSM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupSM"));
    SetRootComponent(PickupSM);
	PickupTexture = CreateDefaultSubobject<UTexture2D>(TEXT("PickupTexture"));

}

// Called when the game starts or when spawned
void ABI_Pickup::BeginPlay()
{
	Super::BeginPlay();
}

void ABI_Pickup::SetGlowEffect(bool Status)
{
	PickupSM->SetRenderCustomDepth(Status);
}