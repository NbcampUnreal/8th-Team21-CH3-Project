// Fill out your copyright notice in the Description page of Project Settings.
// InGameHUD.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InGameHUD.generated.h"

class UInGameUI;

UCLASS()
class TEAM21_CH3_PROJECT_API AInGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	// 게임 모드에서 호출할 UI 갱신 명령 함수
	void RefreshMatchUI(int32 PlayerScore, int32 AIScore, int32 Round);

public:
	void RefreshHealthUI(float CurrentHealth, float MaxHealth);	

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UInGameUI> InGameUIClass;

	UPROPERTY()
	UInGameUI* InGameUIInstance;
};