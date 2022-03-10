// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Character/PlayerCharacter.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMWEAPONGAME_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	TMap<int32, TSoftObjectPtr<APlayerCharacter>> map;
};
