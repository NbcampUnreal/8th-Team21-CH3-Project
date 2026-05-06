
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

	virtual void Tick(float DeltaSeconds) override;

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
	void InputAttackMelee(const FInputActionValue& InValue);
	void TryFire();

	void InputStartZoom(const FInputActionValue& InValue);
	void InputEndZoom(const FInputActionValue& InValue);

protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta =(AllowPrivateAccess))
	TObjectPtr<UInputConfig> CharacterInputConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,meta =(AllowPrivateAccess))
	TObjectPtr<UInputMappingContext> CharacterIMC;

#pragma endregion

#pragma region Effect

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UCameraShakeBase> AttackRangedCameraShake;

#pragma endregion 

#pragma region Zoom

protected:
	float TargetFOV = 70.f;
		//Field Of View 시야 각
	float CurrentFOV = 70.f;

#pragma endregion
};
