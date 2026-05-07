// TeamGameInstance.cpp
#include "TeamGameInstance.h"

UTeamGameInstance::UTeamGameInstance(){
	selectedWeaponType = EWeaponType::Rifle;
	mouseSensitivity = 1.0f;
	masterVolume = 1.0f;
	playerTotalKillCount = 0;
	bIsWin = false;
}

EWeaponType UTeamGameInstance::GetSelectedWeaponType() const{
	return selectedWeaponType;
}

void UTeamGameInstance::SetSelectedWeaponType(EWeaponType weaponType){
	switch (weaponType)
	{
	case EWeaponType::Rifle:
	case EWeaponType::Shotgun:
	case EWeaponType::Pistol:
		selectedWeaponType = weaponType;
		break;
	default:
		selectedWeaponType = EWeaponType::Rifle;
		break;
	}
}

float UTeamGameInstance::GetMouseSensitivity() const{
	return mouseSensitivity;
}

void UTeamGameInstance::SetMouseSensitivity(float value){
	mouseSensitivity = FMath::Clamp(value, 0.5f, 3.0f);
}

float UTeamGameInstance::GetMasterVolume() const{
	return masterVolume;
}

void UTeamGameInstance::SetMasterVolume(float value){
	masterVolume = FMath::Clamp(value, 0.0f, 1.0f);
}

int32 UTeamGameInstance::GetPlayerTotalKillCount() const{
	return playerTotalKillCount;
}

void UTeamGameInstance::SetPlayerTotalKillCount(int32 killCount){
	playerTotalKillCount = FMath::Max(0, killCount);
}

void UTeamGameInstance::AddPlayerKillCount(int32 killCount){
	const int32 safeKillCount = FMath::Max(0, killCount);
	playerTotalKillCount += safeKillCount;
}

bool UTeamGameInstance::GetIsWin() const{
	return bIsWin;
}

void UTeamGameInstance::SetIsWin(bool bNewIsWin){
	bIsWin = bNewIsWin;
}
