// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyClass.h"

// Constructor
AEnemyClass::AEnemyClass() : ABase2DCharacter()
{

}

// Called every frame
void AEnemyClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyClass::BeginPlay()
{
	Super::BeginPlay();

	// Force enemies to face camera while moving
	bUseControllerRotationYaw = false;
	UCharacterMovementComponent * mover = GetCharacterMovement();
	mover->bOrientRotationToMovement = true;
	mover->RotationRate = FRotator(0, 0, 0);
	
}
