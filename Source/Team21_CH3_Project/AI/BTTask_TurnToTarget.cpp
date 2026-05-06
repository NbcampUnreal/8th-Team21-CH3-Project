// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_TurnToTarget.h"
#include "Controller/AI_Controller.h"
#include "Character/NonPlayerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_TurnToTarget::UBTTask_TurnToTarget()
{
	NodeName = TEXT("TurnToTargetActor");
}

EBTNodeResult::Type UBTTask_TurnToTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	AAI_Controller* AIController = Cast<AAI_Controller>(OwnerComp.GetAIOwner());
	checkf(IsValid(AIController) == true, TEXT("Invalid AIController."));

	ANonPlayerCharacter* NPC = Cast<ANonPlayerCharacter>(AIController->GetPawn());
	checkf(IsValid(NPC) == true, TEXT("Invalid NPC."));

	if (ACharacterBase* TargetPC = Cast<ACharacterBase>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AIController->TargetCharacterKey)))
	{
		FVector LookVector = TargetPC->GetActorLocation() - NPC->GetActorLocation();
		LookVector.Z = 0.f;

		FRotator TargetRotation = FRotationMatrix::MakeFromX(LookVector).Rotator();
		NPC->SetActorRotation(FMath::RInterpTo(NPC->GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), 2.f));

		return Result = EBTNodeResult::Succeeded;
	}

	return Result = EBTNodeResult::Failed;
}