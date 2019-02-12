// Fill out your copyright notice in the Description page of Project Settings.

#include "ProtagClass.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AProtagClass::AProtagClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Make Pawn Movement Component
	CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");

	// Make a Mesh
	/*MyMesh = CreateDefaultSubobject<UStaticMeshComponent>("myMesh");*/

	// Make a Spring Arm Attached to the Mesh
	CamBoom = CreateDefaultSubobject<USpringArmComponent>("cameraBoom");
	CamBoom->SetupAttachment(GetCapsuleComponent());

	// Make a camera component and Attach it to the camera boom
	Camera = CreateDefaultSubobject<UCameraComponent>("myCamera");
	Camera->SetupAttachment(CamBoom);

	// Initialize Movement Anim bools
	isHorzMovement = false;
	isVertMovement = false;
}

// Called when the game starts or when spawned
void AProtagClass::BeginPlay()
{
	Super::BeginPlay();

	
	
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

void AProtagClass::moveRight(float axisValue)
{
	if (axisValue == 1.0)
	{
		isHorzMovement = true;
		D("Left");
		GetSprite()->SetFlipbook(walkRightAnim);
		// Rotate the Flipbook
		GetSprite()->SetWorldRotation(FRotator(0.f, 270.f, 0.f));
	}
	else if (axisValue == -1.0)
	{
		isHorzMovement = true;
		D("Right");
		GetSprite()->SetFlipbook(walkRightAnim);
		resetRotation();
	}
	else if (axisValue == 0.0)
	{
		isHorzMovement = false;
		D("No Horizontal Input");
		if (isVertMovement == false)
		{
			GetSprite()->SetFlipbook(idleAnim);
		}
		resetRotation();
	}
	AddMovementInput(GetActorRightVector(), axisValue);
}

void AProtagClass::moveForward(float axisValue)
{
	if (axisValue == 1.0)
	{
		isVertMovement = true;
		D("Backward");
		GetSprite()->SetFlipbook(walkDownAnim);
		resetRotation();
	}
	else if (axisValue == -1.0)
	{
		isVertMovement = true;
		D("Forward");
		GetSprite()->SetFlipbook(walkForwardAnim);
		resetRotation();
	}
	else if (axisValue == 0.0)
	{
		isVertMovement = false;
	}

	AddMovementInput(GetActorForwardVector(), axisValue);
}

void AProtagClass::resetRotation()
{
	GetSprite()->SetWorldRotation(FRotator(0.f, 90.f, 0.f));
}
