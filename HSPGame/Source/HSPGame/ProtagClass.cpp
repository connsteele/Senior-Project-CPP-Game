// Fill out your copyright notice in the Description page of Project Settings.

#include "ProtagClass.h"
#include "GameFramework/FloatingPawnMovement.h"

// On Class Construction
AProtagClass::AProtagClass()
{
	/*
	--- Notes ---
	- Idle animation is set by blueprint so it's visible in the viewport
	*/

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//---  Set up Variables from Parent Classes ---
	// Make Pawn Movement Component
	CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");

	// Make a Spring Arm Attached to the Mesh
	CamBoom = CreateDefaultSubobject<USpringArmComponent>("cameraBoom");
	CamBoom->SetupAttachment(GetCapsuleComponent());

	// Make a camera component and Attach it to the camera boom
	Camera = CreateDefaultSubobject<UCameraComponent>("myCamera");
	Camera->SetupAttachment(CamBoom);

	// Initialize Movement Anim bools
	isHorzMoving = false;
	isVertMoving = false;



}

// Called when the game starts or when spawned
void AProtagClass::BeginPlay()
{
	Super::BeginPlay();

	// Test adding self to battle chars array
	// Get the game mode and cast it
	AHSPGameGameModeBase* gameModeref = (AHSPGameGameModeBase*)GetWorld()->GetAuthGameMode();
	gameModeref->addToBattle((ABase2DCharacter *)this);
}

// Called every frame
void AProtagClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AProtagClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AProtagClass::moveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AProtagClass::moveRight);

}

// Override the Parent Classe's moveRight() function
void AProtagClass::moveRight(float axisValue)
{
	if (axisValue == 1.0)
	{
		isHorzMoving = true;
		D("Left");
		GetSprite()->SetFlipbook(walkRightAnim);
		// Rotate the Flipbook
		GetSprite()->SetWorldRotation(FRotator(0.f, 270.f, 0.f));
	}
	else if (axisValue == -1.0)
	{
		isHorzMoving = true;
		D("Right");
		GetSprite()->SetFlipbook(walkRightAnim);
		resetRotation();
	}
	else if (axisValue == 0.0)
	{
		isHorzMoving = false;
		D("No Horizontal Input");
		if ( isVertMoving == false)
		{
			GetSprite()->SetFlipbook(idleAnim);
		}
		resetRotation();
	}
	Super::AddMovementInput(GetActorRightVector(), axisValue);
}

void AProtagClass::moveForward(float axisValue)
{
	if (axisValue == 1.0)
	{
		isVertMoving = true;
		D("Backward");
		GetSprite()->SetFlipbook(walkDownAnim);
		Super::resetRotation();
	}
	else if (axisValue == -1.0)
	{
		isVertMoving = true;
		D("Forward");
		GetSprite()->SetFlipbook(walkForwardAnim);
		Super::resetRotation();
	}
	else if (axisValue == 0.0)
	{
		 isVertMoving = false;
	}

	Super::AddMovementInput(GetActorForwardVector(), axisValue);
}

void AProtagClass::resetRotation()
{
	GetSprite()->SetWorldRotation(FRotator(0.f, 90.f, 0.f));
}
