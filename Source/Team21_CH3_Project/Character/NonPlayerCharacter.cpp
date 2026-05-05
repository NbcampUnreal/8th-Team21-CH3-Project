// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NonPlayerCharacter.h"

#include "Controller/AI_Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimInstance.h"

ANonPlayerCharacter::ANonPlayerCharacter() : bIsNowAttacking(false)
{
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AAI_Controller::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void ANonPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (false == IsPlayerControlled())
	{
		bUseControllerRotationYaw = false;

		GetCharacterMovement()->bOrientRotationToMovement = false;
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		GetCharacterMovement()->RotationRate = FRotator(0.f, 480.f, 0.f);
	}
}

void ANonPlayerCharacter::BeginAttack()
{
	UAnimInstance* AnimInstance = Cast<UAnimInstance>(GetMesh()->GetAnimInstance());
	checkf(IsValid(AnimInstance) == true, TEXT("Invalid AnimInstance"));

	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
	/*if (IsValid(AnimInstance) == true && IsValid(AttackMeleeMontage) == true && AnimInstance->Montage_IsPlaying(AttackMeleeMontage) == false)
	{
		AnimInstance->Montage_Play(AttackMeleeMontage);

		bIsNowAttacking = true;

		if (OnAttackMontageEndedDelegate.IsBound() == false)
		{
			OnAttackMontageEndedDelegate.BindUObject(this, &ThisClass::EndAttack);
			AnimInstance->Montage_SetEndDelegate(OnAttackMontageEndedDelegate, AttackMeleeMontage);
		}
	}
	*/
	
}

void ANonPlayerCharacter::EndAttack(UAnimMontage* InMontage, bool bInterruped)
{
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);

	bIsNowAttacking = false;

	if (OnAttackMontageEndedDelegate.IsBound() == true)
	{
		OnAttackMontageEndedDelegate.Unbind();
	}
}
