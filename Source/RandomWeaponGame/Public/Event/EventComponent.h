// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EventBase.h"
#include "Delegates/DelegateSignatureImpl.inl"
#include "EventComponent.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EEventEnum : uint8
{
	ATTACKEVENT UMETA(DisplayName = "AttackEvent"),
	HURTEVENT UMETA(DisplayName = "HurtEvent"),
};

UENUM(BlueprintType)
enum class EEventPriorityEnum : uint8
{
	HIGHTEST UMETA(DisplayName = "Hightest"),
	HIGH UMETA(DisplayName = "High"),
	NORMAL UMETA(DisplayName = "Normal"),
	LOW UMETA(DisplayName = "Low"),
	LOWEST UMETA(DisplayName = "Lowest"),
};

UCLASS()
class UEventComponent : public UObject
{
	GENERATED_BODY()

public:
	UEventComponent();

	template <typename UserClass, typename ParamTypes>
	void RegisterEvent(UserClass* instance, typename TMemFunPtrType<false, UserClass, void(ParamTypes)>::Type InFunc);

	template <typename UserClass, typename ParamTypes>
	void UnRegisterEvent(UserClass* instance, typename TMemFunPtrType<false, UserClass, void(ParamTypes)>::Type InFunc);

	template <typename ParamTypes>
	void RaiseEvent(EEventEnum eventType, EEventPriorityEnum eventPriority, ParamTypes eventSource);

	template <typename ParamTypes>
	static TMap<TPair<EEventEnum, EEventPriorityEnum>, TLinkedList<IEventInterface<void(ParamTypes)>>> EventMap;
};
