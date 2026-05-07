// Fill out your copyright notice in the Description page of Project Settings.
// InGameHUD.cpp

#include "InGameHUD.h"
#include "InGameUI.h"
#include "Blueprint/UserWidget.h"

void AInGameHUD::BeginPlay()
{
	Super::BeginPlay();

	if (InGameUIClass)
	{
		InGameUIInstance = CreateWidget<UInGameUI>(GetWorld(), InGameUIClass);

		if (InGameUIInstance)
		{
			InGameUIInstance->AddToViewport();
		}
	}
}

// 점수 및 라운드 갱신용
void AInGameHUD::RefreshMatchUI(int32 PlayerScore, int32 AIScore, int32 Round)
{
	if (InGameUIInstance)
	{
		InGameUIInstance->UpdateMatchInfo(PlayerScore, AIScore, Round);
	}
}

// 체력 바 갱신용
void AInGameHUD::RefreshHealthUI(float CurrentHealth, float MaxHealth)
{
	if (InGameUIInstance)
	{
		InGameUIInstance->UpdateHealth(CurrentHealth, MaxHealth);
	}
}