// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Bomb.h"
#include "EnemyCharacter.h"
#include "MainGameModeBase.h"
#include "MainPlayerController.h"
#include "PlayerHUD.h"

#include "Pickup.h"

#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Engine/Texture2D.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Do not call Tick function for now
	PrimaryActorTick.bCanEverTick = true;

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

	// Sword Collision Sphere
	SwordCollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SwordCollisionComp"));
	SwordCollisionComp->SetupAttachment(GetMesh(), FName("RightShoulder"));
	SwordCollisionComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SwordCollisionComp->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::OnBeginSwordOverlap);


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

	MainPlayerController = Cast<AMainPlayerController>(GetController());
	PlayerHUD = Cast<APlayerHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());

	// Init bomb count
	BombCount = MaxBombCount;

	// Set Init health
	Health = MaxHealth;

	// Init last Pickup
	LastItemSeen = nullptr;

	// Init inventory array
	Inventory.SetNum(MAX_INVENTORY_ITEMS);
}

// Disabled for now
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Raycast every frame;
	Raycast();
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("QuitGame", IE_Pressed, this, &APlayerCharacter::EscapeGameInput);
	PlayerInputComponent->BindAction("SpawnBomb", IE_Pressed, this, &APlayerCharacter::AttempToSpawnBomb);
	PlayerInputComponent->BindAction("DropEquippedItem", IE_Pressed, this, &APlayerCharacter::DropEquippedItem);

	PlayerInputComponent->BindAction("Slash", IE_Pressed, this, &APlayerCharacter::SlashStart);
	PlayerInputComponent->BindAction("Slash", IE_Released, this, &APlayerCharacter::SlashEnd);


	PlayerInputComponent->BindAction("Pickup", IE_Pressed, this, &APlayerCharacter::PickupItem);

	// Handle inventory input
	{
		FInputActionBinding InventoryBinding;

		// We need this bind to execute pause state
		InventoryBinding.bExecuteWhenPaused = true;
		InventoryBinding.ActionDelegate.BindDelegate(this, TEXT("HandleInventoryInput"));
		InventoryBinding.ActionName = TEXT("Inventory");
		InventoryBinding.KeyEvent = IE_Pressed;

		// Binding Inventory action
		PlayerInputComponent->AddActionBinding(InventoryBinding);

	}

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

void APlayerCharacter::SlashStart()
{
	bIsSlashing = true;
	SwordCollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void APlayerCharacter::SlashEnd()
{
	bIsSlashing = false;
	SwordCollisionComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void APlayerCharacter::OnBeginSwordOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != NULL) && (OtherActor != this) && bIsSlashing)
	{
		if (OtherActor->IsA<AEnemyCharacter>())
		{
			float SwordDamageRate = FMath::FRandRange(MinSwordDamageRate, MaxSwordDamageRate);
			Cast<AEnemyCharacter>(OtherActor)->SimpleDamage(SwordDamageRate);
		}
	}
}

float APlayerCharacter::SimpleDamage(float Damage)
{
	Health -= Damage;

	if (Health <= 0 )
	{
		AMainGameModeBase* MainGameModeBase = Cast<AMainGameModeBase>(GetWorld()->GetAuthGameMode());
		if (MainGameModeBase != nullptr)
		{
			MainGameModeBase->PlayerDie();
		}
	}

	return Health;
}

// ------------ Inventory system
// ---------------------------
void APlayerCharacter::Raycast()
{
	// Calculating start and end location
	FVector StartLocation = GetCapsuleComponent()->GetComponentLocation();
	FVector EndLocation = StartLocation + (GetCapsuleComponent()->GetForwardVector() * RaycastRange);


	FHitResult RaycastHit;

	// Raycast should ignore the character
	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActor(this);

	// Raycast
	GetWorld()->LineTraceSingleByChannel(RaycastHit, StartLocation, EndLocation, ECollisionChannel::ECC_WorldDynamic, CollisionQueryParams);

	APickup* Pickup = Cast<APickup>(RaycastHit.GetActor());

	if (LastItemSeen && LastItemSeen != Pickup)
	{
		// If character seen a different pickup then disable the glowing effect on the previous seen item
		LastItemSeen->SetGlowEffect(false);
	}

	if (Pickup)
	{
		// Enable the glow effect on the current item
		LastItemSeen = Pickup;
		Pickup->SetGlowEffect(true);
	}
	else
	{
		LastItemSeen = nullptr;
	}
}

void APlayerCharacter::PickupItem()
{
	if (LastItemSeen)
	{
		// Find first available slot
		int32 AvailableSlot = Inventory.Find(nullptr);

		if (AvailableSlot != INDEX_NONE)
		{
			// Add to first valid slot
			Inventory[AvailableSlot] = LastItemSeen;

			// Destroy item from the game
			LastItemSeen->Destroy();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("You can not carry more then %d items"), MAX_INVENTORY_ITEMS);
		}
	}
}

void APlayerCharacter::HandleInventoryInput()
{
	if (PlayerHUD)
	{
		PlayerHUD->HandleInventoryInput();
	}
}

void APlayerCharacter::SetEquippedItem(UTexture2D* Texture)
{
	if (Texture)
	{
		// For this scenarion we make the assumption that
		// Every pickup has a unique texture.
		// So, in order to set the equipped item we just check every item 
		// inside our Inventory. Once we found an item that has the same image as the
		// Texture image we're passing as a parametr we mark that itemas CurrentlyEquipped
		for (auto It = Inventory.CreateIterator(); It; It++)
		{
			if ((*It) && (*It)->GetPickupTexture() && (*It)->GetPickupTexture()->HasSameSourceArt(Texture) )
			{
				CurrentlyEquippedItem = *It;
				UE_LOG(LogTemp, Warning, TEXT("I've set a new equipped item: %s"), *CurrentlyEquippedItem->GetName());
				break;
			}
		}	
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player has clicked an empty inventory slot"));
	}
}

void APlayerCharacter::DropEquippedItem()
{
	if (CurrentlyEquippedItem != nullptr)
	{
		int32 IndexOfItem;
		if (Inventory.Find(CurrentlyEquippedItem, IndexOfItem))
		{
			// The location for drop
			FVector DropLocation = GetActorLocation() + (GetActorForwardVector() * 200);

			// Making a transform with default rotation and scale. just setting the location
			// that was calculated abouve
			FTransform Transform;
			Transform.SetLocation(DropLocation);

			// Default actor spawn parameters
			FActorSpawnParameters SpawnParameters;
			SpawnParameters.Instigator = this;
			SpawnParameters.Owner = GetController();

			// Spawn the pickup
			APickup* PickupToSpawn = GetWorld()->SpawnActor<APickup>(CurrentlyEquippedItem->GetClass(), Transform, SpawnParameters);

			if (PickupToSpawn != nullptr)
			{
				// Unreferenced intem we're jusp placed
				Inventory[IndexOfItem] = nullptr;
			}	
		}
	}
}