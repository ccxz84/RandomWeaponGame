// Copyright Epic Games, Inc. All Rights Reserved.

#include "RandomWeaponGameGameMode.h"
#include "Character/PlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARandomWeaponGameGameMode::ARandomWeaponGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		// UE_LOG(LogTemp, Log, TEXT("%s"), *PlayerPawnBPClass.Class.Get()->GetName());
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
