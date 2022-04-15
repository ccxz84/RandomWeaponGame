// Fill out your copyright notice in the Description page of Project Settings.


#include "Event/EventComponent.h"

UEventComponent::UEventComponent(){
    
}

template <typename UserClass, typename ParamTypes>
void UEventComponent::RegisterEvent(UserClass* instance, typename TMemFunPtrType<false, UserClass, void(ParamTypes)>::Type InFunc){
    
}

template <typename UserClass, typename ParamTypes>
void UEventComponent::UnRegisterEvent(UserClass* instance, typename TMemFunPtrType<false, UserClass, void(ParamTypes)>::Type InFunc){
    
}

template <typename ParamTypes>
void UEventComponent::RaiseEvent(EEventEnum eventType, EEventPriorityEnum eventPriority, ParamTypes eventSource){
    
}