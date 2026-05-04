

#include "Character/PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Input/InputConfig.h"



APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 400.f;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);

}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = Cast<APlayerController>(GetController());

	if (IsValid(PlayerController))
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (IsValid(Subsystem))
		{
			Subsystem->AddMappingContext(CharacterIMC, 0);
			UE_LOG(LogTemp, Warning, TEXT("AddMappingContext Suceess"));
		}
	}
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* CharacterInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (IsValid(CharacterInputComponent))
	{
		CharacterInputComponent->BindAction(CharacterInputConfig->Move, ETriggerEvent::Triggered, this, &ThisClass::InputMove);
		UE_LOG(LogTemp, Warning, TEXT("InputComponent Bind Suceess"));
	}
}

void APlayerCharacter::InputMove(const FInputActionValue& InValue)
{
	FVector2D MoveVector = InValue.Get<FVector2D>();

	AddMovementInput(GetActorForwardVector(),MoveVector.X);
	AddMovementInput(GetActorRightVector(), MoveVector.Y);
}
