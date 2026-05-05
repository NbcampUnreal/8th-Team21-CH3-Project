// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "NonPlayerCharacter.generated.h"


DECLARE_DELEGATE_TwoParams(FOnAttackMontageEnded, UAnimMontage*, bool /*bInterrupted*/)
/**
 * 
 */
UCLASS()
class TEAM21_CH3_PROJECT_API ANonPlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()

	friend class UBTTask_Attack;
	
public:
	ANonPlayerCharacter();

	virtual void BeginPlay() override;

protected:
	virtual void BeginAttack();

	virtual void EndAttack(UAnimMontage* InMontage, bool bInterruped);

public:
	bool bIsNowAttacking;

protected:

	FOnAttackMontageEnded OnAttackMontageEndedDelegate;

};
