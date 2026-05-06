

#include "Animation/CharacterAnimInstance.h"
#include "Character/CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h" //여러 수학적 로직을 가지고있는 Static 클래스
#include "Character/PlayerCharacter.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	APawn* OwnerPawn = TryGetPawnOwner();

	if (IsValid(OwnerPawn))
	{
		OwnerCharacter = Cast<ACharacterBase>(OwnerPawn);
		OwnerCharacterMovement = OwnerCharacter->GetCharacterMovement();
	}
	bIsUnarmed = true;
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (IsValid(OwnerCharacter) && IsValid(OwnerCharacterMovement)) //캐릭터가 있고, movementcomponent도 있다면
	{
		Velocity = OwnerCharacterMovement->Velocity;

		GroundSpeed = UKismetMathLibrary::VSizeXY(Velocity);
		// Z는 무시하고XY값만 사용
		// 점프 중에도 XY값만 적용

		bIsMove = (KINDA_SMALL_NUMBER < GroundSpeed);
		bIsFalling = OwnerCharacterMovement->IsFalling();
		bIsUnarmed = OwnerCharacter->GetCurrentWeaponAttackAnimMontage() == nullptr ? true : false;
		
		if (APlayerController* OwnerPlayerController = Cast<APlayerController>(OwnerCharacter->GetController()))
		{
			NormalizedCurrentPitch = UKismetMathLibrary::NormalizeAxis(OwnerPlayerController->GetControlRotation().Pitch);
		}
	}
}
