// OutGamePlayerController.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "OutGamePlayerController.generated.h"

class UOutGameRootWidget;

UCLASS()
class TEAM21_CH3_PROJECT_API AOutGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "OutGame UI")
	TSubclassOf<UOutGameRootWidget> RootWidgetClass;

private:
	UPROPERTY(Transient)
	TObjectPtr<UOutGameRootWidget> RootWidgetInstance;
	
public:
	UOutGameRootWidget* GetRootWidget() const;
	
	UFUNCTION()
	void SetViewTargetByTag(FName cameraTag, float blendTime);
};
