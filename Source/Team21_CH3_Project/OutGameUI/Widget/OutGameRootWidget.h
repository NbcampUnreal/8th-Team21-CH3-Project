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
	UFUNCTION(Blueprintable, Category = "OutGame UI")
	void ShowSettings();
	UFUNCTION(BlueprintCallable, Category = "OutGame UI")
	void ShowResult();
	UFUNCTION(BlueprintCallable, Category = "OutGame UI")
	void ShowSelectTransition();


	void ShowTransition(TFunction<void()> action);

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> ScreenSwitcher;
	
	TFunction<void()> pendingTransitionAction;
	
	UFUNCTION()
	void HandleTransitionFadeOutFinished();
	
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UOutGameTransitionWidget> TransitionWidget;
};
