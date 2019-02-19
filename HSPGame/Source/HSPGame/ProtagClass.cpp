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
	CamBoom->SetupAttachment(RootComponent);

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
	turnAP = 0;
	maxTurnAP = 300.f;
	attackCost = 20.f;
	distanceToAP = 5.f;

	// Allow actor to move
	isMoveable = true;
	isHorzMoving = false;
	isVertMoving = false;


	//--- Set up Rotation booleans for correct player orientation when rotating camera 
	// Note: These don't work when placed in the constructor, put here!
	bUseControllerRotationPitch = false; // Don't rotate on this axis when the controller rotates.
	bUseControllerRotationYaw = false; // Don't rotate on this axis when the controller rotates.
	bUseControllerRotationRoll = false; // Don't rotate on this axis when the controller rotates.
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input
	// Don't let the camera rotate when the cotroller does
	CamBoom->bUsePawnControlRotation = false; // Dont rotate the camera arm based on the controller
	Camera->bUsePawnControlRotation = false; // Dont rotate the camera based on the controller
	
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

	// Bindings to Rotate the Camera
	PlayerInputComponent->BindAction("RotateCamera+90", IE_Pressed, this, &AProtagClass::RotateCamPlus);
	PlayerInputComponent->BindAction("RotateCamera-90", IE_Pressed, this, &AProtagClass::RotateCamMinus);


}

// Rotate the Camera + 90 degrees
void AProtagClass::RotateCamPlus()
{
	D("+ ROT CAM");
	
	// Update the cam arm's relative rotation
	CamBoom->AddRelativeRotation(FRotator(0.f, 90.f, 0.f));
	// Update what direction input will move player
	AddControllerYawInput(180.0f);
	AddControllerPitchInput(180.0f);

}

void AProtagClass::RotateCamMinus()
{
	D("- ROT CAM");

	// Update the cam arm's relative rotation
	CamBoom->AddRelativeRotation(FRotator(0.f, -90.f, 0.f));
	// Update what direction input will move player
	AddControllerYawInput(-180.0f);
	AddControllerPitchInput(-180.0f);
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
		// Flip the sprite texture
		
	}
	else if (axisValue == -1.0)
	{
		isHorzMoving = true;
		//D("Right");
		GetSprite()->SetFlipbook(walkRightAnim);
	}
	else if (axisValue == 0.0)
	{
		isHorzMoving = false;
		//D("No Horizontal Input");
		if ( isVertMoving == false)
		{
			GetSprite()->SetFlipbook(idleAnim);
		}
	}

	// find out which way is right
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get right vector 
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	// add movement in that direction
	AddMovementInput(Direction, axisValue);
}

void AProtagClass::moveForward(float axisValue)
{
	if (axisValue == 1.0)
	{
		isVertMoving = true;
		//D("Backward");
		GetSprite()->SetFlipbook(walkDownAnim);
	}
	else if (axisValue == -1.0)
	{
		isVertMoving = true;
		//D("Forward");
		GetSprite()->SetFlipbook(walkForwardAnim);
	}
	else if (axisValue == 0.0)
	{
		 isVertMoving = false;
	}

	// find out which way is forward
	const FRotator Rotation = Controller->GetControlRotation(); // use GetController()?
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get forward vector
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, axisValue);
}


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
	lastRecordedLocation = GetActorLocation();
	//isMoveable = true;
	EnableInput(PC);
	isTurn = true;
	D("Player turn start");
	isBattling = true;
}

void AProtagClass::endTurn()
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	DisableInput(PC);
	isTurn = false;
	Super::endTurn();
}
