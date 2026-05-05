// Fill out your copyright notice in the Description page of Project Settings.
// InGameUI.h

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameUI.generated.h"

class UProgressBar;
class UTextBlock;
class UImage;

UCLASS()
class TEAM21_CH3_PROJECT_API UInGameUI : public UUserWidget
{
	GENERATED_BODY()
	// UI 수치 갱신 호출용 함수
public:
	void UpdateHealth(float CurrentHealth, float MaxHealth);
	void UpdateAmmo(int32 CurrentAmmo, int32 MaxAmmo);

protected:
	virtual void NativeConstruct() override;

protected:
	// 블루프린트 위젯과 연동될 C++ 포인터
	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* AmmoText;

	UPROPERTY(meta = (BindWidget))
	UImage* CrosshairImage;
	
};
