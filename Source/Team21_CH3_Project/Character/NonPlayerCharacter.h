// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "NonPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TEAM21_CH3_PROJECT_API ANonPlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()
	
public:
	ANonPlayerCharacter();

	virtual void BeginPlay() override;

};
