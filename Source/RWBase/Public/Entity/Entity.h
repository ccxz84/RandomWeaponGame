// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Entity.generated.h"

UCLASS()
class RWBASE_API AEntity : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEntity();
	/** Property replication */
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:

	/** The player's maximum health. This is the highest that their health can be, and the value that their health starts at when spawned.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EntityStats", Replicated)
	float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EntityStats", Replicated)
	float CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EntityStats", Replicated)
	float MaxMana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EntityStats", Replicated)
	float CurrentMana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EntityStats", Replicated)
	float RegenHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EntityStats", Replicated)
	float RegenMana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EntityStats", Replicated)
	float Ad;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EntityStats", Replicated)
	float Ap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EntityStats", Replicated)
	float AttackSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EntityStats", Replicated)
	float Movement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EntityStats", Replicated)
	float Armor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EntityStats", Replicated)
	float MagicResistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack", Replicated)
	bool bIsAttack;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UFUNCTION(BlueprintPure, Category="Health")
	FORCEINLINE float GetMaxHealth() const { return MaxHealth; } 

	UFUNCTION(BlueprintPure, Category="Health")
	FORCEINLINE float GetCurrentHealth() const { return CurrentHealth; }

	UFUNCTION(BlueprintPure, Category="Mana")
	FORCEINLINE float GetMaxMana() const { return MaxMana; } 

	UFUNCTION(BlueprintPure, Category="Mana")
	FORCEINLINE float GetCurrentMana() const { return CurrentMana; }

	UFUNCTION(BlueprintPure, Category="Attack")
	FORCEINLINE bool GetIsAttack() const { return bIsAttack; }

	/** Setter for Current Health. Clamps the value between 0 and MaxHealth and calls OnHealthUpdate. Should only be called on the server.*/
	UFUNCTION(BlueprintCallable, Category="Health")
	void SetCurrentHealth(float healthValue);

	UFUNCTION(BlueprintCallable, Category="Mana")
	void SetCurrentMana(float healthValue);

	UFUNCTION(BlueprintCallable, Category="Attack")
	void SetIsAttack(bool IsAttackValue);

	UFUNCTION(BlueprintCallable, Server, reliable, Category="Attack")
	void Attack();
	
	UFUNCTION(BlueprintCallable, Server, reliable,  Category="Attack")
	void AttackEnd();

	// void AttackDamage();

	UFUNCTION(BlueprintCallable, Category = "Health")
	float TakeDamage( float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser ) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
