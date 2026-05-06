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

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UInGameUI> InGameUIClass;

	UPROPERTY()
	UInGameUI* InGameUIInstance;
};