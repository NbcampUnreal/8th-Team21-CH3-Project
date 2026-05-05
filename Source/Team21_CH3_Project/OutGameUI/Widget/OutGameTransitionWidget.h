// OutGameTransitionWidget.h
#pragma once

#include "CoreMinimal.h"
#include "OutGameUI/Widget/OutGameWidgetBase.h"
#include "OutGameTransitionWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFadeOutFinished);

class UWidgetAnimation;

UCLASS()
class TEAM21_CH3_PROJECT_API UOutGameTransitionWidget : public UOutGameWidgetBase
{
	GENERATED_BODY()
	
public:
	virtual void NativeOnInitialized() override;

#pragma region Transition
	
public:
	void PlayFadeOut();
	void PlayFadeIn();
	
	UPROPERTY(BlueprintAssignable, Category = "Transition")
	FOnFadeOutFinished OnFadeOutFinished;
	
private:
	UPROPERTY(meta = (BindWidgetAnim), Transient)
	TObjectPtr<UWidgetAnimation> FadeOutAnim;
	UPROPERTY(meta = (BindWidgetAnim), Transient)
	TObjectPtr<UWidgetAnimation> FadeInAnim;
	
	UFUNCTION()
	void HandleFadeOutFinished();
	UFUNCTION()
	void HandleFadeInFinished();
	
#pragma endregion
	
#pragma region SelectTransition
	
public:
	void PlaySelectTransition();
	
private:
	UFUNCTION()
	void HandleSelectFinished();
	UPROPERTY(meta = (BindWidgetAnim), Transient)
	TObjectPtr<UWidgetAnimation> SelectAnim;
	
#pragma endregion
};
