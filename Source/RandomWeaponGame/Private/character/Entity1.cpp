// Fill out your copyright notice in the Description page of Project Settings.


#include "character/Entity1.h"

// Sets default values
AEntity1::AEntity1()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEntity1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEntity1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEntity1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

