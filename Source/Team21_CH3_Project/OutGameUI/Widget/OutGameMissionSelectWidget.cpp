// OutGameMissionSelect.cpp
#include "OutGameUI/Widget/OutGameMissionSelectWidget.h"
#include "OutGameUI/Widget/OutGameRootWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "OutGameUI/Controller/OutGamePlayerController.h"
#include "Kismet/GameplayStatics.h"

void UOutGameMissionSelectWidget::NativeOnInitialized(){
	Super::NativeOnInitialized();
	
	if (IsValid(EasyButton) == true) EasyButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleLevelClicked);
	if (IsValid(NormalButton) == true) NormalButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleLevelClicked);
	if (IsValid(HardButton) == true) HardButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleLevelClicked);
	if (IsValid(BackButton) == true) BackButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleBackClicked);
	if (IsValid(BackToMapButton) == true) BackToMapButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleBackClicked);
}

void UOutGameMissionSelectWidget::HandleLevelClicked(){
	// UGameplayStatics::OpenLevel(this, TEXT("TestMap"));
	// TODO:Move to Map Logic 
	
	if (AOutGamePlayerController* PC = GetOwningPlayer<AOutGamePlayerController>())
	{
		if (UOutGameRootWidget* RootWidgetInstance = PC->GetRootWidget())
		{
			RootWidgetInstance->ShowTransition([this, PC, RootWidgetInstance]()
			{
				PC->SetViewTargetByTag("CharacterSelectCamera", 0.0f);
				if (IsValid(ScreenSwitcher) == true) ScreenSwitcher->SetActiveWidgetIndex(1);
			});
		}
	}
}

void UOutGameMissionSelectWidget::HandleBackClicked(){
	if (ScreenSwitcher->GetActiveWidgetIndex() == 1)
	{
		if (AOutGamePlayerController* PC = GetOwningPlayer<AOutGamePlayerController>())
		{
			if (UOutGameRootWidget* RootWidgetInstance = PC->GetRootWidget())
			{
				RootWidgetInstance->ShowTransition([this, PC, RootWidgetInstance]()
				{
					PC->SetViewTargetByTag("LobbyCamera", 0.0f);
					if (IsValid(ScreenSwitcher) == true) ScreenSwitcher->SetActiveWidgetIndex(0);
				});
			}
		}
	}
	else{
		if (AOutGamePlayerController* PC = GetOwningPlayer<AOutGamePlayerController>())
		{
			if (UOutGameRootWidget* RootWidgetInstance = PC->GetRootWidget())
			{
				RootWidgetInstance->ShowTransition([this, PC, RootWidgetInstance]()
				{
					RootWidgetInstance->ShowMainMenu();
				});
			}
		}
	}
}

