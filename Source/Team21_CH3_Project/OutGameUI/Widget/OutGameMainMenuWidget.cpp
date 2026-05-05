// OutGameMainMenuWidget.cpp
#include "OutGameUI/Widget/OutGameMainMenuWidget.h"
#include "OutGameUI/Widget/OutGameRootWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "OutGameUI/Controller/OutGamePlayerController.h"
#include "Kismet/KismetSystemLibrary.h"

void UOutGameMainMenuWidget::NativeOnInitialized(){
	Super::NativeOnInitialized();
	
	if (IsValid(ContinueButton) == true)	ContinueButton->OnClicked.AddUniqueDynamic(this, &ThisClass::ShowLobby);
	if (IsValid(PlayButton) == true) PlayButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandlePlayClicked);
	if (IsValid(QuitButton) == true) QuitButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleQuitClicked);
}

void UOutGameMainMenuWidget::ShowLobby(){
	if (IsValid(ScreenSwitcher) == true)
	{
		ScreenSwitcher->SetActiveWidgetIndex(1);
	}
}

void UOutGameMainMenuWidget::HandlePlayClicked(){
	if (AOutGamePlayerController* PC = GetOwningPlayer<AOutGamePlayerController>())
	{
		if (UOutGameRootWidget* RootWidgetInstance = PC->GetRootWidget())
		{
			RootWidgetInstance->ShowTransition([this, PC, RootWidgetInstance]()
			{
				RootWidgetInstance->ShowMissionSelect();
			});
		}
	}
}

void UOutGameMainMenuWidget::HandleQuitClicked(){
	if (AOutGamePlayerController* PC = GetOwningPlayer<AOutGamePlayerController>())
	{
		UKismetSystemLibrary::QuitGame(this, PC, EQuitPreference::Quit, false);
	}
}
