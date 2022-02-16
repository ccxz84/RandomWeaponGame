// Fill out your copyright notice in the Description page of Project Settings.


#include "character/Leesin.h"

// Sets default values
ALeesin::ALeesin()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALeesin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALeesin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALeesin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

