

#include "Character/PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Input/InputConfig.h"
#include "GameFramework/CharacterMovementComponent.h"



APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 400.f;
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->bInheritPitch = true;
	SpringArmComp->bInheritYaw = true;
	SpringArmComp->bInheritRoll = false;
	SpringArmComp->bDoCollisionTest = true;
		//SetRelativeLocation은 BP에서 조정

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);
	CameraComp->bUsePawnControlRotation = false;

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
		CharacterInputComponent->BindAction(CharacterInputConfig->Look, ETriggerEvent::Triggered, this, &ThisClass::InputLook);
		UE_LOG(LogTemp, Warning, TEXT("InputComponent Bind Suceess"));
	}
}

void APlayerCharacter::InputMove(const FInputActionValue& InValue)
{
	FVector2D MoveVector = InValue.Get<FVector2D>();

	const FRotator CharacterRotation = GetController()->GetControlRotation();
	const FRotator CharacterRotationYaw(0.f, CharacterRotation.Yaw, 0.f);

	const FVector FowardVector = FRotationMatrix(CharacterRotationYaw).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(CharacterRotationYaw).GetUnitAxis(EAxis::Y);

	AddMovementInput(GetActorForwardVector(),MoveVector.X);
	AddMovementInput(GetActorRightVector(), MoveVector.Y);
}

void APlayerCharacter::InputLook(const FInputActionValue& InValue)
{
	FVector2D LookVector = InValue.Get<FVector2D>();

	AddControllerYawInput(LookVector.X);
	AddControllerYawInput(LookVector.Y);
}
