// Fill out your copyright notice in the Description page of Project Settings.

#include "Base2DCharacter.h"
#include "HSPGameGameModeBase.h"

// Constructor
ABase2DCharacter::ABase2DCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set the root Component
	RootComponent = GetCapsuleComponent();

	// Attach Vision Collider to Character
	visionSphere = CreateDefaultSubobject<USphereComponent>("VisionCollider");
	visionSphere->SetupAttachment(RootComponent);
	
}

//----- Override Functions from Parent Class
// Called when the game starts or when spawned
void ABase2DCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Initialize the Battle Boolean
	isBattling = false;
	isJumping = false;
}

// Called every frame
void ABase2DCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//--- If in battle calculate distance to AP
	if (isBattling && isTurn) 
	{
		getTurnDistance();
	}

	//--- Make the sprite face player 0's camera
	//FVector CameraLocation = GEngine->GetFirstLocalPlayerController(GetWorld())->PlayerCameraManager->GetCameraLocation() ; // +FVector(-200.f, 0.f, 20.f)
	//FVector objectlocation = GetSprite()->GetComponentLocation();
	//FRotator rotYaw = FRotationMatrix::MakeFromY(CameraLocation - objectlocation).Rotator();
	//FRotator relRot = GetSprite()->RelativeRotation;
	//GetSprite()->SetRelativeRotation(FRotator(relRot.Pitch, rotYaw.Yaw, relRot.Roll));
	//GetSprite()->AddRelativeRotation(FRotator(0.f, 90.f, 0.f));

	//--- Calculate Percentages for UI
	APPercentage = turnAP / maxTurnAP;
	healthPercentage = currHealth / maxHealth;

	/*if (currHealth <= 0) {
		die();
	}*/

	
}


//----- Functions Bound For Collisions
void ABase2DCharacter::inSight(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	// D("base char collide");
}

void ABase2DCharacter::charHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
}

//----- Turn Related Functions
// Called when turn is started
void ABase2DCharacter::startTurn()
{

}
// Called when turn is ended
void ABase2DCharacter::endTurn()
{
	AHSPGameGameModeBase* gameModeref = (AHSPGameGameModeBase*)GetWorld()->GetAuthGameMode();
	gameModeref->nextFighter();
}
// Turn distance moved into AP
void ABase2DCharacter::getTurnDistance()
{
	FVector loc = GetActorLocation();
	float distanceTravelled = (lastRecordedLocation - loc).Size();
	//turn the distance to AP
	turnAP -= (distanceTravelled / distanceToAP);
	lastRecordedLocation = loc;

	if (turnAP <= 0) {
		if (isTurn) {
			endTurn();
		}
	}
}

void ABase2DCharacter::outOfSight(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
}



//----- Movement Functions
void ABase2DCharacter::moveRight()
{
	
}

void ABase2DCharacter::moveForward()
{
	
}



// Called when the character dies
void ABase2DCharacter::die() 
{
	// Give XP to the player

	// Change the sprite to the death 
	//GetSprite()->SetFlipbook(deathAnim);


	//UWidgetLayoutLibrary::RemoveAllWidgets(this);
	//D("Actor is dead");
	//Super::Destroy();

	// Subtract alive players from game mode

}


