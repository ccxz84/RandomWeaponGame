// Fill out your copyright notice in the Description page of Project Settings.


#include "Event/AttackEvent.h"

void UAttackEvent::RegisterEvent(TDelegate<void(FAttackEventSource)>& newDelegate){
    MultiDelegate.Add(newDelegate);
}

void UAttackEvent::UnRegisterEvent(TDelegate<void(FAttackEventSource)>& newDelegate){
    MultiDelegate.Remove(newDelegate.GetHandle());
}

void UAttackEvent::RaiseEvent(FAttackEventSource eventSource){
    MultiDelegate.Broadcast(eventSource);
}