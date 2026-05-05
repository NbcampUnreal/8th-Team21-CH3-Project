
#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputConfig;
class UInputMappingContext;

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

#pragma region Input
private:
	void InputMove(const FInputActionValue& InValue);
	void InputLook(const FInputActionValue& InValue);
	void InputAttackRanged(const FInputActionValue& InValue);
	void TryFire();

protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta =(AllowPrivateAccess))
	TObjectPtr<UInputConfig> CharacterInputConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,meta =(AllowPrivateAccess))
	TObjectPtr<UInputMappingContext> CharacterIMC;

#pragma endregion
};
