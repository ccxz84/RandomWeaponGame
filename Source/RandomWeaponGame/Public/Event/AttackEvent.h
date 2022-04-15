// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Event/EventBase.h"
#include "Utils/Damage/DamageTypes.h"
#include "Delegates/DelegateSignatureImpl.inl"
#include "AttackEvent.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE_OneParam(FDelegate, FAttackEventSource);

class UAttackEvent : public IEventInterface<FAttackEventSource>
{
public:
	void RegisterEvent(TDelegate<void(FAttackEventSource)>& newDelegate) override;
	void UnRegisterEvent(TDelegate<void(FAttackEventSource)>& newDelegate) override;
	void RaiseEvent(FAttackEventSource eventSource) override;
private:
	FDelegate MultiDelegate;
};

USTRUCT()
struct FAttackEventSource{

	GENERATED_BODY()

public:
	FDamageSource DamageSource;
};