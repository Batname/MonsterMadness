// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"


// Sets default values
AMenuCharacter::AMenuCharacter()
{

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set Player to be controlled by lowest numbered player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Setup camera
	ThirdPersonSpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("ThirdPersonSpringArmComp"));
	ThirdPersonSpringArmComp->SetupAttachment(RootComponent);
	ThirdPersonSpringArmComp->TargetArmLength = 300.f;
	ThirdPersonSpringArmComp->bUsePawnControlRotation = true;

	ThirdPersonCameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCameraComp"));
	ThirdPersonCameraComp->SetupAttachment(ThirdPersonSpringArmComp, USpringArmComponent::SocketName);
	ThirdPersonCameraComp->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void AMenuCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMenuCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMenuCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("PerformMeleeHit", IE_Pressed, this, &AMenuCharacter::Attack);

}

void AMenuCharacter::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("AMenuCharacter::Attack"));
}