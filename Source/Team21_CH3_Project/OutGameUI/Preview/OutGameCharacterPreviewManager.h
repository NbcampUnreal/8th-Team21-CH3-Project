// OutGameCharacterPreviewManager.h
#pragma once

#include "CoreMinimal.h"
#include "OutGameUI/Data/OutGameCharacterPreviewData.h"
#include "GameFramework/Actor.h"
#include "OutGameCharacterPreviewManager.generated.h"

class USplineComponent;
class UAnimSequence;

UCLASS()
class TEAM21_CH3_PROJECT_API AOutGameCharacterPreviewManager : public AActor{
	GENERATED_BODY()

public:
	AOutGameCharacterPreviewManager();
	virtual void Tick(float deltaSecond) override;
	
	UFUNCTION(BlueprintCallable, Category = "Preview")
	void ShowCharacter(FName character);

	UFUNCTION(BlueprintCallable, Category = "Preview")
	void ClearPreviewCharacter();
	
	void ClearCurrentCharacter();
private:
	void PlayAnimation();
	
	UPROPERTY(EditAnywhere, Category = "Preview")
	TArray<FOutGameCharacterPreviewData> characterPreviews;
	UPROPERTY()
	TObjectPtr<ACharacter> currentCharacter;
	UPROPERTY()
	TObjectPtr<USplineComponent> currentSpline;
	UPROPERTY()
	TObjectPtr<UAnimSequence> currentAnim;
	
	int32 currentPreviewIndex;
	float currentSplineDistance = 0.0f;
	float currentMoveSpeed = 300.0f;
	bool bMovingToTarget = false;
};
