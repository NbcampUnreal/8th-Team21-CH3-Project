// OutGameCharacterPreviewManager.cpp
#include "OutGameCharacterPreviewManager.h"
#include "GameFramework/Character.h"
#include "Components/SplineComponent.h"

AOutGameCharacterPreviewManager::AOutGameCharacterPreviewManager(){
	PrimaryActorTick.bCanEverTick = true;
}

void AOutGameCharacterPreviewManager::Tick(float deltaSecond){
	Super::Tick(deltaSecond);
	
	if (bMovingToTarget == false) return;
	if (!IsValid(currentCharacter) || !IsValid(currentSpline))
	{
		bMovingToTarget = false;
		return;
	}
	
	currentSplineDistance += currentMoveSpeed * deltaSecond;
	const float splineLength = currentSpline->GetSplineLength();
	
	if (currentSplineDistance >= splineLength)
	{
		currentSplineDistance = splineLength;
		bMovingToTarget = false;
	}
	
	const FVector newLocation = currentSpline->GetLocationAtDistanceAlongSpline(
		currentSplineDistance,
		ESplineCoordinateSpace::World
	);
	const FRotator newRotation = currentSpline->GetRotationAtDistanceAlongSpline(
		currentSplineDistance,
		ESplineCoordinateSpace::World
	);
	
	currentCharacter->SetActorLocationAndRotation(newLocation, newRotation);
	
	if (bMovingToTarget == false)
	{
		PlayAnimation();
	}
}

void AOutGameCharacterPreviewManager::ShowCharacter(FName character){
	ClearCurrentCharacter();
	
	for (int32 i = 0; i < characterPreviews.Num(); i++)
	{
		if (characterPreviews[i].characterId == character)
		{
			currentPreviewIndex = i;
			break;
		}
	}
	
	if (currentPreviewIndex == INDEX_NONE) return;
	const FOutGameCharacterPreviewData data = characterPreviews[currentPreviewIndex];
	if (!IsValid(data.characterClass) || !IsValid(data.movePathActor)) return;
	
	currentSpline = data.movePathActor->FindComponentByClass<USplineComponent>();
	if (IsValid(currentSpline) == false) return;
	
	const FVector spawnLocation = currentSpline->GetLocationAtDistanceAlongSpline(
		0.0f,
		ESplineCoordinateSpace::World
		);

	const FRotator spawnRotation = currentSpline->GetRotationAtDistanceAlongSpline(
		0.0f,
		ESplineCoordinateSpace::World
		);
	
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	
	currentCharacter = GetWorld()->SpawnActor<ACharacter>(
		data.characterClass,
		spawnLocation,
		spawnRotation,
		spawnParams
	);
	
	if (IsValid(currentCharacter) == false) return;
	
	if (IsValid(data.walkSequence) == true)
	{
		currentCharacter->GetMesh()->PlayAnimation(data.walkSequence, true);
	}
	
	currentSplineDistance = 0.0f;
	currentMoveSpeed = data.moveSpeed;
	bMovingToTarget = true;
}

void AOutGameCharacterPreviewManager::ClearCurrentCharacter(){
	if (IsValid(currentCharacter) == true)
	{
		currentCharacter->Destroy();
		currentCharacter = nullptr;
	}
	
	currentSpline = nullptr;
	currentSplineDistance = 0.0f;
	currentPreviewIndex = INDEX_NONE;
	bMovingToTarget = false;
}

void AOutGameCharacterPreviewManager::ClearPreviewCharacter(){
	ClearCurrentCharacter();
}

void AOutGameCharacterPreviewManager::PlayAnimation(){
	if (currentPreviewIndex == INDEX_NONE || !IsValid(currentCharacter)) return;
	
	const FOutGameCharacterPreviewData& data = characterPreviews[currentPreviewIndex];
	
	if (IsValid(data.animSequence))
	{
		currentCharacter->GetMesh()->PlayAnimation(data.animSequence, false);
	}
	
}
