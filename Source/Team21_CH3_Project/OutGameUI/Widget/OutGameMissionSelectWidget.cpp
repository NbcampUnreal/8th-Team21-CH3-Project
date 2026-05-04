// OutGameMissionSelect.cpp
#include "OutGameUI/Widget/OutGameMissionSelectWidget.h"
#include "OutGameUI/Widget/OutGameRootWidget.h"
#include "Components/Button.h"
#include "OutGameUI/Controller/OutGamePlayerController.h"
#include "Kismet/GameplayStatics.h"

void UOutGameMissionSelectWidget::NativeOnInitialized(){
	Super::NativeOnInitialized();
	
	if (IsValid(NormalButton) == true)
	{
		NormalButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleNormalClicked);
	}

	if (IsValid(BackButton) == true)
	{
		BackButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleBackClicked);
	}

}

void UOutGameMissionSelectWidget::HandleNormalClicked(){
	UGameplayStatics::OpenLevel(this, TEXT("TestMap"));
}

void UOutGameMissionSelectWidget::HandleBackClicked(){
	if (AOutGamePlayerController* PC = GetOwningPlayer<AOutGamePlayerController>())
	{
		if (UOutGameRootWidget* RootWidgetInstance = PC->GetRootWidget())
		{
			RootWidgetInstance->ShowMainMenu();
		}
	}
}
