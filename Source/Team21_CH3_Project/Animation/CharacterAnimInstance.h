
#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

class ACharacterBase;
class UCharacterMovementComponent;

UCLASS()
class TEAM21_CH3_PROJECT_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	TObjectPtr<ACharacterBase> OwnerCharacter;
	TObjectPtr<UCharacterMovementComponent> OwnerCharacterMovement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FVector Velocity; //이동 속도

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float GroundSpeed; //걸을때 속력

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	uint8 bIsMove : 1; //ABP에서 사용할 Get변수

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	uint8 bIsFalling : 1;
};
