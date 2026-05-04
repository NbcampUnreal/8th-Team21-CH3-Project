
#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TEAM21_CH3_PROJECT_API APlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()

#pragma region Override ACharacter

public:

	APlayerCharacter();

	virtual void BeginPlay() override;

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,meta =(AllowPrivateAccess))
	TObjectPtr<USpringArmComponent> SpringArmComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TObjectPtr<UCameraComponent> CameraComp;

#pragma endregion

};
