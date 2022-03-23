// Fill out your copyright notice in the Description page of Project Settings.


#include "character/Entity.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"

// Sets default values
AEntity::AEntity()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    this->bReplicates = true;
	MaxHealth = 2100.0f;
	CurrentHealth = MaxHealth;
    MaxMana = 200.0f;
	CurrentMana = MaxMana;
    bIsAttack = false;
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
    DOREPLIFETIME(AEntity, RegenHealth);
    DOREPLIFETIME(AEntity, RegenMana);
    DOREPLIFETIME(AEntity, Ad);
    DOREPLIFETIME(AEntity, Ap);
    DOREPLIFETIME(AEntity, AttackSpeed);
    DOREPLIFETIME(AEntity, Movement);
    DOREPLIFETIME(AEntity, Armor);
    DOREPLIFETIME(AEntity, MagicResistance);
    DOREPLIFETIME(AEntity, bIsAttack);
}

float AEntity::TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    float damageApplied = CurrentHealth - DamageTaken;
    SetCurrentHealth(damageApplied);
    return damageApplied;
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

void AEntity::SetIsAttack(bool IsAttackValue)
{
    if (GetLocalRole() == ROLE_Authority)
    {
        this->bIsAttack = IsAttackValue;
    }
}

void AEntity::Attack_Implementation()
{
    if(!this->bIsAttack)
        this->bIsAttack = true;
}

void AEntity::AttackEnd_Implementation()
{
    if(this->bIsAttack)
        this->bIsAttack = false;
}