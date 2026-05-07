// OutGameMissionSelect.cpp
#include "OutGameUI/Widget/OutGameMissionSelectWidget.h"
#include "OutGameUI/Widget/OutGameRootWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "OutGameUI/Controller/OutGamePlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "OutGameUI/Preview/OutGameCharacterPreviewManager.h"

void UOutGameMissionSelectWidget::NativeOnInitialized(){
	Super::NativeOnInitialized();
	
	if (IsValid(EasyButton) == true) EasyButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleLevelClicked);
	if (IsValid(NormalButton) == true) NormalButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleLevelClicked);
	if (IsValid(HardButton) == true) HardButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleLevelClicked);
	if (IsValid(BackButton) == true) BackButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleBackClicked);
	if (IsValid(BackToMapButton) == true) BackToMapButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleBackClicked);
	if (IsValid(characterSelectButton01) == true) characterSelectButton01->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleCharacter01Clicked);
	if (IsValid(characterSelectButton02) == true) characterSelectButton02->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleCharacter02Clicked);
	if (IsValid(characterConfirmButton) == true) characterConfirmButton->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleConfirmSelectClicked);
}

void UOutGameMissionSelectWidget::HandleLevelClicked(){
	if (AOutGamePlayerController* pc = GetOwningPlayer<AOutGamePlayerController>())
	{
		if (UOutGameRootWidget* rootWidgetInstance = pc->GetRootWidget())
		{
			rootWidgetInstance->ShowTransition([this, pc, rootWidgetInstance]()
			{
				rootWidgetInstance->SetHeaderVisible(false);
				pc->SetViewTargetByTag("CharacterSelectCamera", 0.0f);
				if (IsValid(ScreenSwitcher) == true) ScreenSwitcher->SetActiveWidgetIndex(1);
			});
		}
	}
}

void UOutGameMissionSelectWidget::HandleBackClicked(){
	if (ScreenSwitcher->GetActiveWidgetIndex() == 1)
	{
		if (AOutGamePlayerController* pc = GetOwningPlayer<AOutGamePlayerController>())
		{
			if (UOutGameRootWidget* rootWidgetInstance = pc->GetRootWidget())
			{
				rootWidgetInstance->ShowTransition([this, pc, rootWidgetInstance]()
				{
					pc->SetViewTargetByTag("LobbyCamera", 0.0f);
					if (IsValid(ScreenSwitcher) == true) ScreenSwitcher->SetActiveWidgetIndex(0);
					rootWidgetInstance->ShowWidget(EOutGameWidgetType::MainMenu);
					rootWidgetInstance->SetHeaderVisible(true);
					if (AOutGameCharacterPreviewManager* previewManager = GetPreviewManager())
						previewManager->ClearCurrentCharacter();
				});
			}
		}
	}
	else{
		if (AOutGamePlayerController* pc = GetOwningPlayer<AOutGamePlayerController>())
		{
			if (UOutGameRootWidget* rootWidgetInstance = pc->GetRootWidget())
			{
				rootWidgetInstance->ShowWidget(EOutGameWidgetType::MainMenu);
				// rootWidgetInstance->ShowTransition([this, pc, rootWidgetInstance](){}
			}
		}
	}
}

AOutGameCharacterPreviewManager* UOutGameMissionSelectWidget::GetPreviewManager() const{
	TArray<AActor*> foundActors;
	UGameplayStatics::GetAllActorsOfClass(
		this,
		AOutGameCharacterPreviewManager::StaticClass(),
		foundActors
	);

	if (foundActors.Num() <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("PreviewManager not found"));
		return nullptr;
	}
	
	return Cast<AOutGameCharacterPreviewManager>(foundActors[0]);
}

void UOutGameMissionSelectWidget::HandleCharacter01Clicked(){
	HandleCharacterSelectClicked("Character01");
}

void UOutGameMissionSelectWidget::HandleCharacter02Clicked(){
	HandleCharacterSelectClicked("Character02");
}

void UOutGameMissionSelectWidget::HandleCharacterSelectClicked(FName characterId){
	if (AOutGamePlayerController* pc = GetOwningPlayer<AOutGamePlayerController>())
	{
		if (UOutGameRootWidget* rootWidgetInstance = pc->GetRootWidget())
		{
			rootWidgetInstance->ShowSelectTransition();
		}
	}
	
	AOutGameCharacterPreviewManager* previewManager = GetPreviewManager();

	if (!IsValid(previewManager))
	{
		UE_LOG(LogTemp, Warning, TEXT("PreviewManager cast failed"));
		return;
	}

	previewManager->ShowCharacter(characterId);
}

void UOutGameMissionSelectWidget::HandleConfirmSelectClicked(){
	// TODO: MoveMap Logic and give map, character data
	
	if (AOutGamePlayerController* pc = GetOwningPlayer<AOutGamePlayerController>())
	{
		if (UOutGameRootWidget* rootWidgetInstance = pc->GetRootWidget())
		{
			rootWidgetInstance->ShowTransition([this]()
			{
				UGameplayStatics::OpenLevel(this, TEXT("TestMap"));
			});
		}
	}
}

