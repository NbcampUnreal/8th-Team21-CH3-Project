// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interaction.h"
#include "ItemBox.generated.h"

UCLASS()
class TEAM21_CH3_PROJECT_API AItemBox : public AActor, public IInteraction
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBox();

	virtual void Interact(AActor* Interactor) override;

protected:
	
	void GiveRandomItem(AActor* TargetActor);

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UStaticMeshComponent* Boxcomponent;

	UPROPERTY(EditAnywhere, Category = "Settings")
	bool bIsOpened = false;
};
