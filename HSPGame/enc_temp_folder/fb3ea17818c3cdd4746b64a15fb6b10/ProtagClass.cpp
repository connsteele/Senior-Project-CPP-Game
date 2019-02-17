// Fill out your copyright notice in the Description page of Project Settings.

#include "ProtagClass.h"
#include "GameFramework/FloatingPawnMovement.h"

// On Class Construction
AProtagClass::AProtagClass()
	: ABase2DCharacter() //Call Parent Constructor
{
	/*
	--- Notes ---
	- Idle animation is set by blueprint so it's visible in the viewport
	*/

	//---  Set up Variables from Parent Classes ---
	// Make Pawn Movement Component
	CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");

	// Make a Spring Arm Attached to the Mesh
	CamBoom = CreateDefaultSubobject<USpringArmComponent>("cameraBoom");
	CamBoom->SetupAttachment(GetCapsuleComponent());

	// Make a camera component and Attach it to the camera boom
	Camera = CreateDefaultSubobject<UCameraComponent>("myCamera");
	Camera->SetupAttachment(CamBoom);

	visionSphere->SetSphereRadius(300.f);

	
}

//--- Functions From Parent Classes
// Called when the game starts or when spawned
void AProtagClass::BeginPlay()
{
	//Super call
	Super::BeginPlay();

	// Show the cursor in the game and enable events
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		PC->bShowMouseCursor = true;
		PC->bEnableClickEvents = true;
		PC->bEnableMouseOverEvents = true;
		
	}


	//Event setups
	GetCapsuleComponent()->OnComponentHit.RemoveDynamic(this, &AProtagClass::charHit);
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AProtagClass::charHit);
	visionSphere->SetGenerateOverlapEvents(true);
	visionSphere->SetNotifyRigidBodyCollision(true);
	visionSphere->OnComponentBeginOverlap.RemoveDynamic(this, &AProtagClass::inSight);
	visionSphere->OnComponentBeginOverlap.AddDynamic(this, &AProtagClass::inSight);

	//Variable declarations
	currHealth = 100.f;
	maxHealth = 100.f;
	turnAP = 200.f;
	maxTurnAP = 300.f;
	attackCost = 20.f;
	distanceToAP = 5.f;

	// Allow actor to move
	isMoveable = true;
	isHorzMoving = false;
	isVertMoving = false;

	
}

// Called every frame
void AProtagClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (isBattling) {
		getTurnDistance();
	}
}

// Called to bind functionality to input
void AProtagClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AProtagClass::moveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AProtagClass::moveRight);
	// Bind the mouse click to a function
	PlayerInputComponent->BindAction("CursorClicked", IE_Pressed, this, &AProtagClass::cursorClick);

}

void AProtagClass::cursorClick()
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	FHitResult HitResult;
	PC->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), true, HitResult);
	FVector HitResLoc= HitResult.Location;
	SetActorLocation(HitResLoc);
	D(FString::SanitizeFloat(HitResLoc.X));
}

// Override the Parent Classe's moveRight() function
void AProtagClass::moveRight(float axisValue)
{
	if (axisValue == 1.0)
	{
		isHorzMoving = true;
		//D("Left");
		GetSprite()->SetFlipbook(walkRightAnim);
		// Rotate the Flipbook
		GetSprite()->SetWorldRotation(FRotator(0.f, 270.f, 0.f));
	}
	else if (axisValue == -1.0)
	{
		isHorzMoving = true;
		//D("Right");
		GetSprite()->SetFlipbook(walkRightAnim);
		resetRotation();
	}
	else if (axisValue == 0.0)
	{
		isHorzMoving = false;
		//D("No Horizontal Input");
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
		//D("Backward");
		GetSprite()->SetFlipbook(walkDownAnim);
		Super::resetRotation();
	}
	else if (axisValue == -1.0)
	{
		isVertMoving = true;
		//D("Forward");
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

//--- Overlap Events
// On Player Capsule Component Hit
//UFUNCTION()
//void AProtagClass::protagHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//	//D("Protag Overlap!");
//
//	// Casts return Null if they fail
//	AEnemySlime * slimeRef = Cast<AEnemySlime>(OtherActor);
//	if (slimeRef)
//	{
//		//D("Hit Enemy Slime!");
//	}
//}
//
UFUNCTION()
void AProtagClass::inSight(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	D("Player Vision Sphere Hit");
	// Test adding self to battle chars array
	// Get the game mode and cast it
	if ((Cast<AEnemyClass>(OtherActor) != NULL) && (Cast<UCapsuleComponent>(OtherComp)) && (isBattling == false))
	{
		isBattling = true;
		AHSPGameGameModeBase* gameModeref = (AHSPGameGameModeBase*)GetWorld()->GetAuthGameMode();
		gameModeref->addToBattle(this, "Protag"); // maybe cast this to (ABase2DCharacter *)
		D("Player Enters Battle");
		gameModeref->nextFighter();
	}
	
}

UFUNCTION()
void AProtagClass::charHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	
	D(FString::FromInt(currHealth));

}

void AProtagClass::startTurn() {
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	turnAP = 0;
	//isMoveable = true;
	//EnableInput(PC);
	isTurn = true;
	D("Player turn start");
	isBattling = true;
}

void AProtagClass::endTurn()
{
	turnAP = 0;
}

void AProtagClass::getTurnDistance()
{
	Super::getTurnDistance();
	if (turnAP >= maxTurnAP) {
		if (isTurn) {
			endTurn();
		}
	}
}
