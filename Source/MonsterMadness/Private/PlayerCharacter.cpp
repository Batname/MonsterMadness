// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Bomb.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Do not call Tick function for now
	PrimaryActorTick.bCanEverTick = false;

	// Set Player to be controlled by lowest number player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	// Set turn rates
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let just affect the camera
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f); // at rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Camera Boom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.f;
	CameraBoom->bUsePawnControlRotation = true;

	// Follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// Init bomb count
	BombCount = MaxBombCount;
}

// Disabled for now
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("QuitGame", IE_Pressed, this, &APlayerCharacter::EscapeGameInput);
	PlayerInputComponent->BindAction("SpawnBomb", IE_Pressed, this, &APlayerCharacter::AttempToSpawnBomb);


	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &APlayerCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LockUp", this, &APawn::AddControllerPitchInput);

}

void APlayerCharacter::MoveForward(float Value)
{
	MovementInput(Value, EAxis::X);
}

void APlayerCharacter::MoveRight(float Value)
{
	MovementInput(Value, EAxis::Y);
}

void APlayerCharacter::MovementInput(float Value, EAxis::Type Axis)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(Axis);
		AddMovementInput(Direction, Value);
	}
}

void APlayerCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void APlayerCharacter::EscapeGameInput()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}

void APlayerCharacter::AttempToSpawnBomb()
{
	if (HasBombs())
	{
		BombCount--;

		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Instigator = this;
		SpawnParameters.Owner = GetController();

		// Spawn the bomb
		GetWorld()->SpawnActor<ABomb>(BP_Bomb, GetActorLocation() + GetActorForwardVector() * 200, GetActorRotation(), SpawnParameters);
	}
}