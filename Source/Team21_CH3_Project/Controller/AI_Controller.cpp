// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/AI_Controller.h"

#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetSystemLibrary.h"

const float AAI_Controller::PatrolRadius(2000.f);
int32 AAI_Controller::ShowAIDebug(0);
const FName AAI_Controller::StartPatrolPositionKey(TEXT("StartPatrolPosition"));
const FName AAI_Controller::EndPatrolPositionKey(TEXT("EndPatrolPosition"));
const FName AAI_Controller::TargetCharacterKey(TEXT("TargetCharacter"));


FAutoConsoleVariableRef CVarShowAIDebug(
	TEXT("NXProject.ShowAIDebug"),
	AAI_Controller::ShowAIDebug,
	TEXT(""),
	ECVF_Cheat
	);
AAI_Controller::AAI_Controller()
{
	Blackboard = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard"));
	BrainComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BrainComponent"));
}

void AAI_Controller::BeginPlay()
{
	Super::BeginPlay();
	APawn* ControlledPawn = GetPawn();
	if (IsValid(ControlledPawn) == true)
	{
		BeginAI(ControlledPawn);
	}
}

void AAI_Controller::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	EndAI();

	Super::EndPlay(EndPlayReason);
}

void AAI_Controller::BeginAI(APawn* InPawn)
{
	UBlackboardComponent* BlackboardComponent = Cast<UBlackboardComponent>(Blackboard);
	if (IsValid(BlackboardComponent) == true)
	{
		if (UseBlackboard(BlackboardDataAsset, BlackboardComponent) == true)
		{
			bool bRunSucceeded = RunBehaviorTree(BehaviorTree);
			checkf(bRunSucceeded == true, TEXT("Fail to run behavior Tree."));

			BlackboardComponent->SetValueAsVector(StartPatrolPositionKey, InPawn->GetActorLocation());
			if (ShowAIDebug == 1)
			{
				UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("BeginAI()")));
			}
		}
	}
}

void AAI_Controller::EndAI()
{
	UBehaviorTreeComponent* BehaviorTreeComponent = Cast<UBehaviorTreeComponent>(BrainComponent);
	if (IsValid(BehaviorTreeComponent) == true)
	{
		BehaviorTreeComponent->StopTree();

		if (ShowAIDebug == 1)
		{
			UKismetSystemLibrary::PrintString(this,FString::Printf(TEXT("EndIA()")));
		}
	}

}