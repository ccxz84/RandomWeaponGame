// Copyright Epic Games, Inc. All Rights Reserved.

#include "RandomWeaponGameGameMode.h"
#include "RandomWeaponGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARandomWeaponGameGameMode::ARandomWeaponGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
