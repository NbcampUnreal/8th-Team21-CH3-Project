// OutGameMissionSelect.h
#pragma once

#include "CoreMinimal.h"
#include "OutGameUI/Widget/OutGameWidgetBase.h"
#include "OutGameMissionSelectWidget.generated.h"

class UButton;
class UWidgetSwitcher;

UCLASS(Abstract, Blueprintable)
class TEAM21_CH3_PROJECT_API UOutGameMissionSelectWidget : public UOutGameWidgetBase{
	GENERATED_BODY()
	
public:
	virtual void NativeOnInitialized() override;
	
	//UFUNCTION(BlueprintCallable, Category = "OutGame UI")
	//void ShowCharacterSelect();
	
protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> ScreenSwitcher;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> EasyButton;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> NormalButton;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> HardButton;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> BackButton; 
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> BackToMapButton; 
	
	UFUNCTION()
	void HandleLevelClicked();
	UFUNCTION()
	void HandleBackClicked();
};
