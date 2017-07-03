// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuCharacter.h"
#include "MenuPlayerAnimInstance.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AMenuCharacter::AMenuCharacter()
{

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

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
	
	AnimInstanceRef = Cast<UMenuPlayerAnimInstance>(GetMesh()->GetAnimInstance());

	// First Idle animation
	{
		FTimerHandle TimerHandle;
		FTimerDelegate TimerDel;

		TimerDel.BindUFunction(this, TEXT("RunIdleSwordMontage"));

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDel, 5.f, false);
	}

	// Idle animaiton loop
	{
		FTimerHandle TimerHandle;
		FTimerDelegate TimerDel;

		TimerDel.BindUFunction(this, TEXT("RunIdleSwordMontage"));

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDel, 60.f, true);
	}
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
	if (AnimInstanceRef)
	{
		AnimInstanceRef->Attack();
	}
}

void AMenuCharacter::RunIdleSwordMontage()
{
	if (AnimInstanceRef)
	{
		AnimInstanceRef->RunIdleSwordMontage();
	}
}