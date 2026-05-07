// Fill out your copyright notice in the Description page of Project Settings.
// ShooterInGameMode.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooterInGameMode.generated.h"

UCLASS()
class TEAM21_CH3_PROJECT_API AShooterInGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AShooterInGameMode();

protected:
	virtual void BeginPlay() override;

public:
	// 캐릭터가 사망했을 때 호출할 함수 (bIsPlayer가 true면 플레이어 사망 -> AI 득점)
	UFUNCTION(BlueprintCallable, Category = "Match Rules")
	void OnCharacterDied(bool bIsPlayer);

	// 라운드 제어 함수
	void StartRound();
	void EndRound();
	void EndMatch(bool bPlayerWon);

protected:
	// 게임 상태를 기억할 변수들
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Match State")
	int32 CurrentRound;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Match State")
	int32 PlayerScore;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Match State")
	int32 AIScore;

	// 목표 승리 점수 (5판 3선승제)
	const int32 TargetScoreToWin = 3;
};