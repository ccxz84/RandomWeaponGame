// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MainGameState.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EGameState : uint8
{
    State_Ready UMETA(DisplayName = "Ready"),
    State_Start UMETA(DisplayName = "Start"),
};

UCLASS()
class AMainGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	EGameState MainGameState;
};
