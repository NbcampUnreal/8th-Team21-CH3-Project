
#include "Gimmick/Ammo.h"
#include "Gimmick/PickupComponent.h"
#include "Character/PlayerCharacter.h"

AAmmo::AAmmo()
{
	PrimaryActorTick.bCanEverTick = false;

	Pickupcomponent = CreateDefaultSubobject<UPickupComponent>(TEXT("Pickupcomponent"));
	SetRootComponent(Pickupcomponent);

}

void AAmmo::BeginPlay()
{
	Super::BeginPlay();
	
	Pickupcomponent->OnPickUp.AddDynamic(this, &ThisClass::HandleOnPickUp);
}

void AAmmo::HandleOnPickUp(APlayerCharacter* InPickUpCharacter)
{
	if (IsValid(InPickUpCharacter) == false)
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Ammo Picked Up!"));

	Pickupcomponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	Destroy();
}


