// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_Controller.generated.h"

class UBlackboardData;
class UBehaviorTree;
/**
 * 
 */
UCLASS()
class TEAM21_CH3_PROJECT_API AAI_Controller : public AAIController
{
	GENERATED_BODY()
	
	friend class ANonPlayerCharacter;
public:
	AAI_Controller();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void BeginAI(APawn* InPawn);
	void EndAI();

public:
	static const float PatrolRadius;
	static int32 ShowAIDebug;
	static const FName StartPatrolPositionKey;
	static const FName EndPatrolPositionKey;
	static const FName TargetCharacterKey;
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (AllowPrivateAccess))
	TObjectPtr<UBlackboardData> BlackboardDataAsset;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (AllowPrivateAccess))
	TObjectPtr<UBehaviorTree> BehaviorTree;
};
