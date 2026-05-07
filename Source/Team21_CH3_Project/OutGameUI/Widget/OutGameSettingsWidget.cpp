// OutGameSettingsWidget.cpp
#include "OutGameUI/Widget/OutGameSettingsWidget.h"
#include "Components/Button.h"
#include "Components/ComboBoxString.h"
#include "Components/Slider.h"
#include "Components/TextBlock.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundMix.h"
#include "Sound/SoundClass.h"
#include "Game/TeamGameInstance.h"
#include "OutGameUI/Widget/OutGameRootWidget.h"
#include "OutGameUI/Controller/OutGamePlayerController.h"


void UOutGameSettingsWidget::NativeOnInitialized(){
	Super::NativeOnInitialized();
	
	if (IsValid(mouseSensitivitySlider)) mouseSensitivitySlider->OnValueChanged.AddUniqueDynamic(this, &ThisClass::HandleMouseSensitivityChanged);
	if (IsValid(masterVolumeSlider)) masterVolumeSlider->OnValueChanged.AddUniqueDynamic(this, &ThisClass::HandleMasterVolumeChanged);
	if (IsValid(graphicsQualityComboBox)) graphicsQualityComboBox->OnSelectionChanged.AddUniqueDynamic(this, &ThisClass::HandleGraphicsQualityChanged);
	if (IsValid(applyButton)) applyButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleApplyClicked);
	if (IsValid(backButton)) backButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleBackClicked);
	
	pendingGraphicsQuality = 2;
}

void UOutGameSettingsWidget::HandleMouseSensitivityChanged(float value){
	if (UGameInstance* GameInstance = GetWorld()->GetGameInstance())
	{
		if (UTeamGameInstance* TeamGameInstance = Cast<UTeamGameInstance>(GameInstance))
		{
			TeamGameInstance->SetMouseSensitivity(value);
		}
	}
	
	mouseSensitivityText->SetText(FText::FromString(FString::Printf(TEXT("%.1f"), value)));
}

void UOutGameSettingsWidget::HandleMasterVolumeChanged(float value){
	UGameplayStatics::SetSoundMixClassOverride(
		this,
		soundMix,
		masterSoundClass,
		value,
		1.0f,
		0.0f,
		true
		);
	
	masterVolumeText->SetText(FText::FromString(FString::Printf(TEXT("%.0f"), value)));
}

void UOutGameSettingsWidget::HandleGraphicsQualityChanged(FString selectedItem, ESelectInfo::Type selectionType){
	if (selectedItem == TEXT("Low")) pendingGraphicsQuality = 0;
	else if (selectedItem == TEXT("Medium")) pendingGraphicsQuality = 1;
	else if (selectedItem == TEXT("High")) pendingGraphicsQuality = 2;
	else if (selectedItem == TEXT("Epic")) pendingGraphicsQuality = 3;
	else if (selectedItem == TEXT("Cinematic")) pendingGraphicsQuality = 4;
}

void UOutGameSettingsWidget::HandleApplyClicked(){
	if (UGameUserSettings* gameUserSettings = GEngine->GetGameUserSettings())
	{
		gameUserSettings->SetOverallScalabilityLevel(pendingGraphicsQuality); // 0 Low, 1 Medium, 2 High, 3Epic, 4Cinematic
		gameUserSettings->ApplySettings(false);
		gameUserSettings->SaveSettings();
	}
}

void UOutGameSettingsWidget::HandleBackClicked(){
	if (AOutGamePlayerController* PC = GetOwningPlayer<AOutGamePlayerController>())
	{
		if (UOutGameRootWidget* RootWidgetInstance = PC->GetRootWidget())
		{
			RootWidgetInstance->ShowMainMenu();
		}
	}
}
