
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

class APlayerCharacter;
class UPickupComponent;

UCLASS()
class TEAM21_CH3_PROJECT_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void HandleOnPickUp(APlayerCharacter* InPickUpCharacter);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UPickupComponent> PickupComponent;



};
