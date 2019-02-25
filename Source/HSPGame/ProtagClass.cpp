// Fill out your copyright notice in the Description page of Project Settings.

#include "ProtagClass.h"
#include "GameFramework/FloatingPawnMovement.h"

// On Class Construction
AProtagClass::AProtagClass() : ABase2DCharacter()
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
	Super::BeginPlay(); // Super call

	canAttack = false;
	isInside = false;

	//--- Show the cursor in the game and enable events
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		PC->bShowMouseCursor = true;
		PC->bEnableClickEvents = true;
		PC->bEnableMouseOverEvents = true;
		
	}

	//--- Set Up Dynamic Functions
	GetCapsuleComponent()->OnComponentHit.RemoveDynamic(this, &AProtagClass::charHit);
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AProtagClass::charHit);
	visionSphere->SetGenerateOverlapEvents(true);
	visionSphere->SetNotifyRigidBodyCollision(true);
	visionSphere->OnComponentBeginOverlap.RemoveDynamic(this, &AProtagClass::inSight);
	visionSphere->OnComponentBeginOverlap.AddDynamic(this, &AProtagClass::inSight);

	//--- Stat Related Variable Initialization
	maxHealth = 100.f;
	currHealth = 100.f;
	maxTurnAP = 300.f;
	turnAP = 300.f;
	attackCost = 20.f;
	distanceToAP = 6.f; // Used as divisor to turn the length of distance moved into AP
	isMoveable = true; // Allow actor to move
	isHorzMoving = false; // Used for horizontal animation
	isVertMoving = false; // Used for vertical animation


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
	FVector CursorClickLoc = HitResult.Location; // Get the vector where the trace hit in the world
	
	// D(FString::SanitizeFloat(CursorClickLoc.X));

	if (canAttack) {

		if (magicAttack)
		{
			UWorld * world = GetWorld();
			if (world)
			{
				FActorSpawnParameters spawnParams;
				spawnParams.Owner = this;

				FRotator protagRot = GetActorRotation();
				// Move the attack location slightly off the ground
				FVector atkSpawnLoc = FVector(CursorClickLoc.X, CursorClickLoc.Y, CursorClickLoc.Z + 15.f);

				// Spawn a magic attack at the cursor's location
				world->SpawnActor(magicAttack, &atkSpawnLoc, &protagRot, spawnParams);
				turnAP -= magicAttack->GetDefaultObject<AAttacks>()->apCost;
			}
		}
	}
}

// Override the Parent Classe's moveRight() function
void AProtagClass::moveRight(float axisValue)
{
	if (axisValue == 1.0)
	{
		isHorzMoving = true;
		//D("Left");
		GetSprite()->SetFlipbook(walkLeftAnim);
		// Flip the sprite texture
		//GetSprite()->SetMaterial(0, mirrorHMaterial);
	}
	else if (axisValue == -1.0)
	{
		isHorzMoving = true;
		//D("Right");
		GetSprite()->SetFlipbook(walkRightAnim);
		//GetSprite()->SetMaterial(0, defaultMaterial);
	}
	else if (axisValue == 0.0)
	{
		isHorzMoving = false;
		//D("No Horizontal Input");
		if ( isVertMoving == false)
		{
			GetSprite()->SetFlipbook(idleAnim);
			//GetSprite()->SetMaterial(0, defaultMaterial);
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
	if (!isHorzMoving) // Let horizontal animations handle diagnol movement
	{
		if (axisValue == 1.0)
		{
			isVertMoving = true;
		
			//D("Down");
			GetSprite()->SetFlipbook(walkDownAnim);
			//GetSprite()->SetMaterial(0, defaultMaterial);
		
		
		}
		else if (axisValue == -1.0)
		{
			isVertMoving = true;
			//D("Forward");
			GetSprite()->SetFlipbook(walkForwardAnim);
			//GetSprite()->SetMaterial(0, defaultMaterial);
		}
	}
	if (axisValue == 0.0)
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
	turnAP = maxTurnAP;
	lastRecordedLocation = GetActorLocation();
	//isMoveable = true;
	EnableInput(PC);
	isTurn = true;
	D("Player turn start");
	// isBattling = true;
}

void AProtagClass::endTurn()
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	DisableInput(PC);
	isTurn = false;
	Super::endTurn();
}
