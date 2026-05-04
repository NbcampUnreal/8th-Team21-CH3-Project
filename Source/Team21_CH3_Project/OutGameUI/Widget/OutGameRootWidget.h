// OutGameRootWidget.h
#pragma once

#include "CoreMinimal.h"
#include "OutGameUI/Widget/OutGameWidgetBase.h"
#include "OutGameRootWidget.generated.h"

class UWidgetSwitcher;

UCLASS(Abstract, Blueprintable)
class TEAM21_CH3_PROJECT_API UOutGameRootWidget : public UOutGameWidgetBase{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "OutGame UI")
	void ShowMainMenu();
	UFUNCTION(BlueprintCallable, Category = "OutGame UI")
	void ShowMissionSelect();
	UFUNCTION(BlueprintCallable, Category = "OutGame UI")
	void ShowResult();

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> ScreenSwitcher;
};
