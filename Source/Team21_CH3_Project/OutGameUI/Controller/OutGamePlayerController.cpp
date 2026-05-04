// OutGamePlayerController.cpp
#include "OutGameUI/Controller/OutGamePlayerController.h"
#include "Blueprint/UserWidget.h"
#include "OutGameUI/Widget/OutGameRootWidget.h"
#include "Kismet/GameplayStatics.h"

void AOutGamePlayerController::BeginPlay(){
	Super::BeginPlay();
	
	if (!IsLocalController()) return;
	
	TArray<AActor*> FoundCameras;
	UGameplayStatics::GetAllActorsWithTag(this, TEXT("LobbyCamera"), FoundCameras);
	
	if (FoundCameras.Num() > 0 && IsValid(FoundCameras[0]))
	{
		SetViewTargetWithBlend(FoundCameras[0], 0.0f);
	}
	
	if (IsValid(RootWidgetClass) == true)
	{
		RootWidgetInstance = CreateWidget<UOutGameRootWidget>(this, RootWidgetClass);
		if (IsValid(RootWidgetInstance) == true)
		{
			RootWidgetInstance->AddToViewport();
		}
	}
	
	bShowMouseCursor = true;
	
	FInputModeUIOnly InputMode;
	SetInputMode(InputMode);
}

UOutGameRootWidget* AOutGamePlayerController::GetRootWidget() const{
	if (IsValid(RootWidgetInstance) == true) return RootWidgetInstance;
	return nullptr;
}