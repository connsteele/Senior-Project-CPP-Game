// Fill out your copyright notice in the Description page of Project Settings.

#include "Base2DCharacter.h"

// Sets default values
ABase2DCharacter::ABase2DCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Circle collider for characters
	/*CircCollider = CreateDefaultSubobject<USphereComponent>("VisionCollider");
	CircCollider->SetupAttachment(GetCapsuleComponent());*/
}

// Called when the game starts or when spawned
void ABase2DCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABase2DCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABase2DCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Base2DCharacter's Function Definitions
void ABase2DCharacter::moveRight()
{
	
}

void ABase2DCharacter::moveForward()
{
	
}

void ABase2DCharacter::resetRotation()
{
	GetSprite()->SetWorldRotation(FRotator(0.f, 90.f, 0.f));
}


