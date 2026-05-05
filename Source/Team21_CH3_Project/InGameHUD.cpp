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