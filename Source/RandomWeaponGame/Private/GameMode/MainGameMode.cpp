// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MainGameMode.h"
#include "UObject/SoftObjectPath.h"
#include "Math/UnrealMathUtility.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/AssetManager.h"
#include "Engine/ObjectLibrary.h"

void AMainGameMode::SelectCharacter(APlayerController* NewPlayer) {
    int32 idx = FMath::RandRange(0, this->CharacterList.Num()-1);

    if(CharacterList[idx].Get()){
        SetCharacter(CharacterList[idx], NewPlayer);
    }
    else{
        FSoftObjectPath stream = CharacterList[idx].ToSoftObjectPath();
        FStreamableManager& assetLoader = UAssetManager::GetStreamableManager();
        assetLoader.RequestAsyncLoad(stream, FStreamableDelegate::CreateUObject(this, &AMainGameMode::SetCharacter, CharacterList[idx], NewPlayer));
    }
}

void AMainGameMode::SetCharacter(TSoftClassPtr<UObject> CharacterPtr, APlayerController* NewPlayer ){
    if(CharacterPtr.Get() && CharacterPtr.Get()->GetSuperClass()->GetName() == "PlayerCharacter"){
        FActorSpawnParameters params;
        params.Owner = NewPlayer; 
        GetWorld()->DestroyActor(NewPlayer->GetCharacter());
        APlayerCharacter* Character = GetWorld()->SpawnActor<APlayerCharacter>(CharacterPtr.Get(), NewPlayer->K2_GetActorLocation(), NewPlayer->K2_GetActorRotation(), params);
        NewPlayer->Possess(Character);
    }
    else{
        UE_LOG(LogTemp, Log, TEXT("%s Load Error"), *CharacterPtr.ToString());
        UE_LOG(LogTemp, Log, TEXT("%d"), CharacterPtr.Get());
        UE_LOG(LogTemp, Log, TEXT("%s %d"), *CharacterPtr.Get()->GetSuperClass()->GetName(), CharacterPtr.Get()->GetSuperClass()->GetName() == "APlayerCharacter");
    }
}

void AMainGameMode::PostLogin(APlayerController* NewPlayer){
    Super::PostLogin(NewPlayer);
    this->SelectCharacter(NewPlayer);
}