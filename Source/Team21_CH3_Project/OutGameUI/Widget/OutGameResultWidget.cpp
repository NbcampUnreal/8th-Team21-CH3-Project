// OutGameResultWidget.cpp
#include "OutGameUI/Widget/OutGameResultWidget.h"
#include "OutGameUI/Controller/OutGamePlayerController.h"
#include "OutGameUI/Widget/OutGameRootWidget.h"
#include "Components/Button.h"

void UOutGameResultWidget::NativeOnInitialized(){
	Super::NativeOnInitialized();
	
	if (IsValid(ReturnToLobbyButton) == true) ReturnToLobbyButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleReturnToLobby);
}

void UOutGameResultWidget::HandleReturnToLobby(){
	if (AOutGamePlayerController* PC = GetOwningPlayer<AOutGamePlayerController>())
	{
		if (UOutGameRootWidget* rootWidgetInstance = Cast<UOutGameRootWidget>(PC->GetRootWidget()))
		{
			rootWidgetInstance->ShowWidget(EOutGameWidgetType::MainMenu);
		}
	}
}
