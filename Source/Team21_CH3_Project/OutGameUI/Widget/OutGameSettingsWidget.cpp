// OutGameSettingsWidget.cpp
#include "OutGameUI/Widget/OutGameSettingsWidget.h"
#include "Components/Button.h"
#include "Components/ComboBoxString.h"
#include "Components/Slider.h"
#include "GameFramework/GameUserSettings.h"

void UOutGameSettingsWidget::NativeOnInitialized(){
	Super::NativeOnInitialized();
	
	if (IsValid(mouseSensitivitySlider)) mouseSensitivitySlider->OnValueChanged.AddUniqueDynamic(this, &ThisClass::HandleMouseSensitivityChanged);
	if (IsValid(masterVolumeSlider)) masterVolumeSlider->OnValueChanged.AddUniqueDynamic(this, &ThisClass::HandleMasterVolumeChanged);
	if (IsValid(graphicsQualityComboBox)) graphicsQualityComboBox->OnSelectionChanged.AddUniqueDynamic(this, &ThisClass::HandleGraphicsQualityChanged);
	if (IsValid(applyButton)) applyButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleApplyClicked);
	if (IsValid(backButton)) backButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleBackClicked);
}

void UOutGameSettingsWidget::HandleMouseSensitivityChanged(float value){
	// TODO: GameInstance MouseSensitivity = value;
}

void UOutGameSettingsWidget::HandleMasterVolumeChanged(float value){  }

void UOutGameSettingsWidget::HandleGraphicsQualityChanged(FString selectedItem, ESelectInfo::Type selectionType){
	
	
	if (UGameUserSettings* gameUserSettings = GEngine->GetGameUserSettings())
	{
		gameUserSettings->SetOverallScalabilityLevel(S); // 0 Low, 1 Medium, 2 High, 3Epic, 4Cinematic
		gameUserSettings->ApplySettings(false);
		gameUserSettings->SaveSettings();
	}
}

void UOutGameSettingsWidget::HandleApplyClicked(){  }

void UOutGameSettingsWidget::HandleBackClicked(){  }
