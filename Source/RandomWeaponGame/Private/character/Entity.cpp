// Fill out your copyright notice in the Description page of Project Settings.


#include "character/Entity.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"

// Sets default values
AEntity::AEntity()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MaxHealth = 2100.0f;
	CurrentHealth = MaxHealth;
    MaxMana = 2100.0f;
	CurrentMana = MaxMana;
}

// Called when the game starts or when spawned
void AEntity::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEntity::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEntity::GetLifetimeReplicatedProps(TArray <FLifetimeProperty> & OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    //Replicate current health.
    DOREPLIFETIME(AEntity, MaxHealth);
    DOREPLIFETIME(AEntity, CurrentHealth);
    DOREPLIFETIME(AEntity, MaxMana);
    DOREPLIFETIME(AEntity, CurrentMana);
}

void AEntity::SetCurrentHealth(float healthValue)
{
    if (GetLocalRole() == ROLE_Authority)
    {
        CurrentHealth = FMath::Clamp(healthValue, 0.f, MaxHealth);
    }
}

void AEntity::SetCurrentMana(float manaValue)
{
    if (GetLocalRole() == ROLE_Authority)
    {
        CurrentMana = FMath::Clamp(manaValue, 0.f, MaxMana);
    }
}

