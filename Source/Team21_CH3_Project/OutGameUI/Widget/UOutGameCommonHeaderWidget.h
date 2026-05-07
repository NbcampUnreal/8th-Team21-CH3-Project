// UOutGameCommonHeaderWidget.h
#pragma once

#include "CoreMinimal.h"
#include "OutGameWidgetBase.h"
#include "UOutGameCommonHeaderWidget.generated.h"

class UButton;

UCLASS()
class TEAM21_CH3_PROJECT_API UUOutGameCommonHeaderWidget : public UOutGameWidgetBase{
	GENERATED_BODY()
	
public:
	virtual void NativeOnInitialized() override;
	
private:
	UPROPERTY(meta =(BindWidget))
	TObjectPtr<UButton> playButton;
	UPROPERTY(meta =(BindWidget))
	TObjectPtr<UButton> weaponsButton;
	UPROPERTY(meta =(BindWidget))
	TObjectPtr<UButton> storeButton;
	UPROPERTY(meta =(BindWidget))
	TObjectPtr<UButton> settingsButton;
	
	UFUNCTION()
	void HandlePlayClicked();
	UFUNCTION()
	void HandleWeaponsClicked();
	UFUNCTION()
	void HandleStoreButton();
	UFUNCTION()
	void HandleSettingsClicked();
	
};
