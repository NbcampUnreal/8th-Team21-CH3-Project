// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

void AInGameGameMode::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* playerController = UGameplayStatics::GetPlayerController(this, 0);
	if (IsValid(playerController) == true)
	{
		FInputModeGameOnly inputMode;
		playerController->SetInputMode(inputMode);
		playerController->bShowMouseCursor = false;
	}
}
