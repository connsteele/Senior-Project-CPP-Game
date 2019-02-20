// Fill out your copyright notice in the Description page of Project Settings.

#include "Base2DCharacter.h"
#include "HSPGameGameModeBase.h"

// Sets default values
ABase2DCharacter::ABase2DCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set the root Component
	RootComponent = GetCapsuleComponent();

	// Attach Vision Collider to Character
	visionSphere = CreateDefaultSubobject<USphereComponent>("VisionCollider");
	visionSphere->SetupAttachment(RootComponent);

	/*defaultMaterial = CreateDefaultSubobject<UMaterialInstance>("DefaultMaterial");
	mirrorHMaterial = CreateDefaultSubobject<UMaterialInstance>("MirrorHMaterial");*/

	
}

// Called when the game starts or when spawned
void ABase2DCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Initialize the Battle Boolean
	isBattling = false;
}

// Called every frame
void ABase2DCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//--- If in battle calculate distance to AP
	if (isBattling) 
	{
		getTurnDistance();
	}

	//--- Make the sprite face player 0's camera
	FVector CameraLocation = GEngine->GetFirstLocalPlayerController(GetWorld())->PlayerCameraManager->GetCameraLocation() ; // +FVector(-200.f, 0.f, 20.f)
	FVector objectlocation = GetSprite()->GetComponentLocation();
	FRotator rotYaw = FRotationMatrix::MakeFromY(CameraLocation - objectlocation).Rotator();
	FRotator relRot = GetSprite()->RelativeRotation;
	GetSprite()->SetRelativeRotation(FRotator(relRot.Pitch, rotYaw.Yaw, relRot.Roll));
	GetSprite()->AddRelativeRotation(FRotator(0.f, 90.f, 0.f));

	//--- Calculate Percentages for UI
	APPercentage = turnAP / maxTurnAP;
	healthPercentage = currHealth / maxHealth;

	
}

//UFUNCTION()
//void ABase2DCharacter::onHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//	D("Overlap with char capsule component!");
//}
//
UFUNCTION()
void ABase2DCharacter::inSight(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	D("base char collide");
}

void ABase2DCharacter::charHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
}

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

// Base2DCharacter's Function Definitions
void ABase2DCharacter::moveRight()
{
	
}

void ABase2DCharacter::moveForward()
{
	
}

//void ABase2DCharacter::resetRotation()
//{
//	GetSprite()->SetWorldRotation(FRotator(0.f, 90.f, 0.f));
//
//}

void ABase2DCharacter::endTurn()
{
	AHSPGameGameModeBase* gameModeref = (AHSPGameGameModeBase*)GetWorld()->GetAuthGameMode();
	gameModeref->nextFighter();
}

void ABase2DCharacter::startTurn()
{
}

void die() {
	//AActor::Destroy();
}


