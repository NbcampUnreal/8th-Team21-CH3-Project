// OutGameTransitionWidget.cpp
#include "OutGameUI/Widget/OutGameTransitionWidget.h"
#include "Animation/WidgetAnimation.h"

void UOutGameTransitionWidget::NativeOnInitialized(){
	Super::NativeOnInitialized();
	
	if (IsValid(FadeOutAnim))
	{
		FWidgetAnimationDynamicEvent FadeOutFinishedEvent;
		FadeOutFinishedEvent.BindDynamic(this, &ThisClass::HandleFadeOutFinished);
		BindToAnimationFinished(FadeOutAnim, FadeOutFinishedEvent);
	}
	
	if (IsValid(FadeInAnim))
	{
		FWidgetAnimationDynamicEvent FadeInFinishedEvent;
		FadeInFinishedEvent.BindDynamic(this, &ThisClass::HandleFadeInFinished);
		BindToAnimationFinished(FadeInAnim, FadeInFinishedEvent);
	}
}

void UOutGameTransitionWidget::PlayFadeOut(){
	SetVisibility(ESlateVisibility::Visible);
	
	if (IsValid(FadeOutAnim)) PlayAnimation(FadeOutAnim);
}

void UOutGameTransitionWidget::PlayFadeIn(){
	if (IsValid(FadeInAnim)) PlayAnimation(FadeInAnim);
}

void UOutGameTransitionWidget::HandleFadeOutFinished(){
	OnFadeOutFinished.Broadcast();
}

void UOutGameTransitionWidget::HandleFadeInFinished(){
	SetVisibility(ESlateVisibility::Collapsed);
}


