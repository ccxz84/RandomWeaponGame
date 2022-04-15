// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

/**
 * 
 */

template <typename ParamTypes>
class IEventInterface
{

public:
	virtual void RegisterEvent(TDelegate<void(ParamTypes)>& newDelegate);

	virtual void UnRegisterEvent(TDelegate<void(ParamTypes)>& newDelegate);

	virtual void RaiseEvent(ParamTypes eventSource);
};

