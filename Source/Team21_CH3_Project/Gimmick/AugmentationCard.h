
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "AugmentationCard.generated.h"



UENUM(BlueprintType)
enum class EAugmentType : uint8
{
    AttackDamage,
    MoveSpeed,
    MaxHP,
    ItemCapacity
};

USTRUCT(BlueprintType)
struct FAugmentTableData : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EAugmentType Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MinValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UnitText;
};

USTRUCT(BlueprintType)
struct FAugmentResult
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    EAugmentType Type;

    UPROPERTY(BlueprintReadWrite)
    FString DisplayTitle;

    UPROPERTY(BlueprintReadWrite)
    FString Description;

    UPROPERTY(BlueprintReadWrite)
    float FinalValue;
};


class UAugmentWidget; 

UCLASS()
class TEAM21_CH3_PROJECT_API AAugmentCard : public AActor
{
    GENERATED_BODY()

public:
    AAugmentCard();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    class UBoxComponent* CollisionBox;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    class UStaticMeshComponent* CardMesh;

    UPROPERTY(EditAnywhere, Category = "Data")
    UDataTable* AugmentDataTable;

    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<UUserWidget> AugmentWidgetClass;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);
};
