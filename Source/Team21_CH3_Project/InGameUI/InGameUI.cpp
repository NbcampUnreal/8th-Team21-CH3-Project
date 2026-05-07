// Fill out your copyright notice in the Description page of Project Settings.
// InGameUI.cpp

#include "InGameUI.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void UInGameUI::NativeConstruct()
{
	Super::NativeConstruct();

	// UI가 화면에 처음 생성될 때 보여줄 기본값 세팅
	UpdateHealth(100.f, 100.f);
	UpdateAmmo(30, 30);

	// 처음에 0점, 1라운드로 보이게 초기화
	UpdateMatchInfo(0, 0, 1);
}

void UInGameUI::UpdateHealth(float CurrentHealth, float MaxHealth)
{
	if (HealthBar && MaxHealth > 0.f)
	{
		HealthBar->SetPercent(CurrentHealth / MaxHealth);
	}
}

void UInGameUI::UpdateAmmo(int32 CurrentAmmo, int32 MaxAmmo)
{
	if (AmmoText)
	{
		FString AmmoString = FString::Printf(TEXT("%d / %d"), CurrentAmmo, MaxAmmo);
		AmmoText->SetText(FText::FromString(AmmoString));
	}
}

void UInGameUI::UpdateMatchInfo(int32 PlayerScore, int32 AIScore, int32 Round)
{
	if (PlayerScoreText)
	{
		PlayerScoreText->SetText(FText::AsNumber(PlayerScore));
	}

	if (AIScoreText)
	{
		AIScoreText->SetText(FText::AsNumber(AIScore));
	}

	if (RoundText)
	{
		RoundText->SetText(FText::FromString(FString::Printf(TEXT("ROUND %d"), Round)));
	}
}