
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class AWeapon;

UCLASS()
class TEAM21_CH3_PROJECT_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();

	UAnimMontage* GetCurrentWeaponAttackAnimMontage() const;


public:
	TObjectPtr<AWeapon> CurrentWeapon;

	static int32 ShowAttackRangedDebug;
};
