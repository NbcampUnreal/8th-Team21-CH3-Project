// OutGameCharacterPreviewData.h
#pragma once

#include "CoreMinimal.h"
#include "OutGameCharacterPreviewData.generated.h"

USTRUCT(BlueprintType)
struct TEAM21_CH3_PROJECT_API FOutGameCharacterPreviewData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName characterId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ACharacter> characterClass;
	UPROPERTY(EditInstanceOnly)
	TObjectPtr<AActor> movePathActor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float moveSpeed = 300.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UAnimSequence> animSequence;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Preview")
	TObjectPtr<UAnimSequence> walkSequence;
};
