// OutGameRootWidget.cpp
#include "OutGameUI/Widget/OutGameRootWidget.h"
#include "Components/WidgetSwitcher.h"

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


