
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputConfig.generated.h"

class UInputAction;

UCLASS()
class TEAM21_CH3_PROJECT_API UInputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TObjectPtr<UInputAction> Move;

};
