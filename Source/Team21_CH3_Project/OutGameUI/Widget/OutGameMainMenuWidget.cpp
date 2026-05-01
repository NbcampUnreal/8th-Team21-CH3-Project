// OutGameMainMenuWidget.cpp
#include "OutGameUI/Widget/OutGameMainMenuWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "OutGameUI/Controller/OutGamePlayerController.h"
#include "Kismet/KismetSystemLibrary.h"

void UOutGameMainMenuWidget::NativeOnInitialized(){
	Super::NativeOnInitialized();
	
	ContinueButton->OnClicked.AddUniqueDynamic(this, &ThisClass::ShowLobby);
	PlayButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandlePlayClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleQuitClicked);
}

void UOutGameMainMenuWidget::ShowLobby(){
	if (IsValid(ScreenSwitcher) == true)
	{
		ScreenSwitcher->SetActiveWidgetIndex(0);
	}
}

void UOutGameMainMenuWidget::HandlePlayClicked(){
	if (AOutGamePlayerController* PC = GetOwningPlayer<AOutGamePlayerController>())
	{
		PC->ShowMissionSelect();
	}
}

void UOutGameMainMenuWidget::HandleQuitClicked(){
	if (AOutGamePlayerController* PC = GetOwningPlayer<AOutGamePlayerController>())
	{
		UKismetSystemLibrary::QuitGame(this, PC, EQuitPreference::Quit, false);
	}
}
