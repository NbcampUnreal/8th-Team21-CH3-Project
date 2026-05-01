// OutGameMissionSelect.cpp
#include "OutGameUI/Widget/OutGameMissionSelectWidget.h"
#include "Components/Button.h"
#include "OutGameUI/Widget/OutGameMainMenuWidget.h"

void UOutGameMissionSelectWidget::NativeOnInitialized(){
	NormalButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleNormalClicked);
	BackButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleBackClicked);
}

void UOutGameMissionSelectWidget::HandleNormalClicked(){
	// OpenLevel logic
}

void UOutGameMissionSelectWidget::HandleBackClicked(){
	
}
