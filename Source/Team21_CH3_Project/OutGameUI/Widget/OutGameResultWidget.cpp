// OutGameResultWidget.cpp
#include "OutGameUI/Widget/OutGameResultWidget.h"
#include "Components/Button.h"

void UOutGameResultWidget::NativeOnInitialized(){
	Super::NativeOnInitialized();
	
	if (IsValid(ReturnToLobbyButton) == true) ReturnToLobbyButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleReturnToLobby);
}

void UOutGameResultWidget::HandleReturnToLobby(){
	
}
