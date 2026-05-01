// OutGamePlayerController.cpp
#include "OutGameUI/Controller/OutGamePlayerController.h"
#include "Blueprint/UserWidget.h"
#include "OutGameUI/Widget/OutGameRootWidget.h"

void AOutGamePlayerController::BeginPlay(){
	Super::BeginPlay();
	
	if (!IsLocalController()) return;
	
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

void AOutGamePlayerController::ShowMissionSelect(){
	if (IsValid(RootWidgetInstance) == true)
	{
		RootWidgetInstance->ShowMissionSelect();
	}
}
