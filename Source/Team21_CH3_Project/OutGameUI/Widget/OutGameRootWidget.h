// OutGameRootWidget.h
#pragma once

#include "CoreMinimal.h"
#include "OutGameUI/Widget/OutGameWidgetBase.h"
#include "OutGameRootWidget.generated.h"

class UWidgetSwitcher;
class UOutGameTransitionWidget;

UCLASS()
class TEAM21_CH3_PROJECT_API UOutGameRootWidget : public UOutGameWidgetBase{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	
	UFUNCTION(BlueprintCallable, Category = "OutGame UI")
	void ShowMainMenu();
	UFUNCTION(BlueprintCallable, Category = "OutGame UI")
	void ShowMissionSelect();
	UFUNCTION(BlueprintCallable, Category = "OutGame UI")
	void ShowResult();

	void ShowTransition(TFunction<void()> InAction);

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> ScreenSwitcher;
	
	TFunction<void()> PendingTransitionAction;
	
	UFUNCTION()
	void HandleTransitionFadeOutFinished();
	
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UOutGameTransitionWidget> TransitionWidget;
};
