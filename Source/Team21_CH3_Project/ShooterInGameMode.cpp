// Fill out your copyright notice in the Description page of Project Settings.
// ShooterInGameMode.cpp

#include "ShooterInGameMode.h"
#include "InGameUI/InGameHUD.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

AShooterInGameMode::AShooterInGameMode()
{
	// 시작 시 0점, 0라운드로 초기화
	CurrentRound = 0;
	PlayerScore = 0;
	AIScore = 0;
}

void AShooterInGameMode::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		FInputModeGameOnly InputModeData;
		PC->SetInputMode(InputModeData);

		PC->bShowMouseCursor = false;
	}
	StartRound();
}

void AShooterInGameMode::StartRound()
{
	CurrentRound++;

	// HUD를 찾아내서 화면의 UI(라운드, 점수)를 갱신하라고 명령!
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		AInGameHUD* MyHUD = Cast<AInGameHUD>(PC->GetHUD());
		if (MyHUD)
		{
			// 방금 전 우리가 HUD에 만들었던 그 함수입니다!
			MyHUD->RefreshMatchUI(PlayerScore, AIScore, CurrentRound);
		}
	}
}

void AShooterInGameMode::OnCharacterDied(bool bIsPlayer)
{
	// 1. 점수 올리기
	if (bIsPlayer)
	{
		AIScore++;
	}
	else
	{
		PlayerScore++;
	}

	// 2. 점수가 변했으니 HUD에게 UI 화면 다시 그리라고 명령!
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		AInGameHUD* MyHUD = Cast<AInGameHUD>(PC->GetHUD());
		if (MyHUD)
		{
			MyHUD->RefreshMatchUI(PlayerScore, AIScore, CurrentRound);
		}
	}

	// 3. 누군가 3점을 달성했는지 확인
	EndRound();
}

void AShooterInGameMode::EndRound()
{
	if (PlayerScore >= TargetScoreToWin)
	{
		EndMatch(true); // 플레이어 승리
	}
	else if (AIScore >= TargetScoreToWin)
	{
		EndMatch(false); // AI 승리
	}
	else
	{
		// 아직 3점이 아니면 다음 라운드로 진행
		StartRound();
	}
}

void AShooterInGameMode::EndMatch(bool bPlayerWon)
{
	// 게임이 완전히 끝났을 때의 처리 (로그 출력)
	if (bPlayerWon)
	{
		UE_LOG(LogTemp, Warning, TEXT("MATCH END: PLAYER WINS!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MATCH END: AI WINS!"));
	}
}