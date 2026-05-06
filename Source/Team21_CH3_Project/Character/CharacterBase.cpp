

#include "Character/CharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Item/Weapon.h"

int32 ACharacterBase::ShowAttackRangedDebug = 0;

FAutoConsoleVariableRef CVarShowAttackRangedDebug(
	TEXT("SX.ShowAttackRangedDebug"),
	ACharacterBase::ShowAttackRangedDebug,
	TEXT(""),
	ECVF_Cheat
);

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	float CapsuleHeight = 90.f;
	float CapsuleRadius = 40.f;

	GetCapsuleComponent()->InitCapsuleSize(CapsuleRadius, CapsuleHeight); //캡슐컴포넌트 Size

	FVector CharacterPosition(0.f, 0.f, -CapsuleHeight); //캐릭터 초기 위치
	FRotator CharacterRotation(0.f, -90.f, 0.f); //캐릭터 초기 회전방향
	GetMesh()->SetRelativeLocationAndRotation(CharacterPosition, CharacterRotation);//생성한 매시를 해당위치, 회전방향의 뷰포트에 위치	
	GetMesh()->SetCollisionProfileName(TEXT("MyCharacterMesh"));

	GetCharacterMovement()->MaxWalkSpeed = 500.f; //이동속도
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f; //최저속도(이동시작시 속도)
	GetCharacterMovement()->JumpZVelocity = 600.f; // 점프시 튕겨 올라가는 속도
	GetCharacterMovement()->AirControl = 0.5f; //공중에서 컨트롤 정도
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f; // 이동키를 뗐을때 감속속도
}

UAnimMontage* ACharacterBase::GetCurrentWeaponAttackAnimMontage() const
{
	if (IsValid(CurrentWeapon) == true)
	{
		return CurrentWeapon->GetAttackMontage();
	}
	return nullptr;
}



