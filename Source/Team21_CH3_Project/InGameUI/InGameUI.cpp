// Fill out your copyright notice in the Description page of Project Settings.
// InGameUI.cpp

#include "InGameUI.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void UInGameUI::NativeConstruct()
{
	Super::NativeConstruct();

	// UI가 화면에 처음 생성될 때 보여줄 기본값 세팅 (테스트용)
	UpdateHealth(100.f, 100.f);
	UpdateAmmo(30, 30);
}

void UInGameUI::UpdateHealth(float CurrentHealth, float MaxHealth)
{
	// 포인터가 유효한지, 그리고 0으로 나누는 에러가 발생하지 않도록 MaxHealth가 0보다 큰지 검사
	if (HealthBar && MaxHealth > 0.f)
	{
		// 프로그레스 바는 0.0 ~ 1.0 사이의 비율(%) 값을 사용하므로 나누기 연산 진행
		HealthBar->SetPercent(CurrentHealth / MaxHealth);
	}
}

void UInGameUI::UpdateAmmo(int32 CurrentAmmo, int32 MaxAmmo)
{
	// 포인터가 유효한지 검사
	if (AmmoText)
	{
		// "%d" 자리에 숫자를 넣어서 "30 / 30" 형태로 문자열 배치
		FString AmmoString = FString::Printf(TEXT("%d / %d"), CurrentAmmo, MaxAmmo);

		// 만들어진 문자열을 텍스트 블록에 적용
		AmmoText->SetText(FText::FromString(AmmoString));
	}
}