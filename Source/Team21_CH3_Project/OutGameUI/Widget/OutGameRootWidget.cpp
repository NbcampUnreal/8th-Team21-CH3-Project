// OutGameRootWidget.cpp
#include "OutGameUI/Widget/OutGameRootWidget.h"
#include "Components/WidgetSwitcher.h"
#include "OutGameUI/Widget/OutGameTransitionWidget.h"

void UOutGameRootWidget::NativeOnInitialized(){
	Super::NativeOnInitialized();
	
	if (IsValid(TransitionWidget) == true) TransitionWidget->OnFadeOutFinished.AddDynamic(this, &ThisClass::HandleTransitionFadeOutFinished);
}

void UOutGameRootWidget::ShowMainMenu()
{
	if (IsValid(ScreenSwitcher) == true)
	{
		ScreenSwitcher->SetActiveWidgetIndex(0);
	}
}

void UOutGameRootWidget::ShowMissionSelect()
{
	if (IsValid(ScreenSwitcher) == true)
	{
		ScreenSwitcher->SetActiveWidgetIndex(1);
	}
}

void UOutGameRootWidget::ShowResult()
{
	if (IsValid(ScreenSwitcher) == true)	{
		ScreenSwitcher->SetActiveWidgetIndex(2);
	}
}

void UOutGameRootWidget::ShowSelectTransition(){
	if (IsValid(TransitionWidget) == true) TransitionWidget->PlaySelectTransition();
}

void UOutGameRootWidget::ShowTransition(TFunction<void()> action){
	pendingTransitionAction = MoveTemp(action);
	
	if (IsValid(TransitionWidget) == true) TransitionWidget->PlayFadeOut();
}

void UOutGameRootWidget::HandleTransitionFadeOutFinished(){
	if (pendingTransitionAction)
	{
		pendingTransitionAction();
		pendingTransitionAction = nullptr;
	}
	if (IsValid(TransitionWidget) == true)
	{
		TransitionWidget->PlayFadeIn();
	}
}

