// OutGameSettingsWidget.h
#pragma once

#include "CoreMinimal.h"
#include "OutGameWidgetBase.h"
#include "OutGameSettingsWidget.generated.h"

class UButton;
class USlider;
class UComboBoxString;

UCLASS()
class TEAM21_CH3_PROJECT_API UOutGameSettingsWidget : public UOutGameWidgetBase{
	GENERATED_BODY()
	
public:
	virtual void NativeOnInitialized() override;
	
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USlider> mouseSensitivitySlider; 
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USlider> masterVolumeSlider;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UComboBoxString> graphicsQualityComboBox;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> applyButton;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> backButton;
	
	UFUNCTION()
	void HandleMouseSensitivityChanged(float value);
	UFUNCTION()
	void HandleMasterVolumeChanged(float value);
	UFUNCTION()
	void HandleGraphicsQualityChanged(FString selectedItem, ESelectInfo::Type selectionType);
	UFUNCTION()
	void HandleApplyClicked();
	UFUNCTION()
	void HandleBackClicked();
};
