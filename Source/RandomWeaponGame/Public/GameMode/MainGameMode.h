// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPtr.h"
#include "Character/PlayerCharacter.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void PostLogin(APlayerController* NewPlayer);
	UFUNCTION(BlueprintCallable)
	void SelectCharacter(APlayerController* NewPlayer);
	UFUNCTION(BlueprintCallable, Category = "Test")
	void SetCharacter(TSoftClassPtr<UObject> Character, APlayerController* NewPlayer);
	
private:
	UPROPERTY(config)
	TArray<TSoftClassPtr<UObject>> CharacterList;
};
