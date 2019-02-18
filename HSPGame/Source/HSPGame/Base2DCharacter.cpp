// Fill out your copyright notice in the Description page of Project Settings.

#include "Base2DCharacter.h"

// Sets default values
ABase2DCharacter::ABase2DCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Attach Vision Collider to Character
	visionSphere = CreateDefaultSubobject<USphereComponent>("VisionCollider");
	visionSphere->SetupAttachment(GetCapsuleComponent());


	// Initialize the Battle Boolean
	isBattling = false;
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
	turnAP = (distanceTravelled / distanceToAP) + turnAP;
	lastRecordedLocation = loc;

	D(FString::SanitizeFloat(turnAP));

	if (turnAP >= maxTurnAP) {
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

void ABase2DCharacter::resetRotation()
{
	GetSprite()->SetWorldRotation(FRotator(0.f, 90.f, 0.f));

}

void ABase2DCharacter::endTurn()
{
}

void ABase2DCharacter::startTurn()
{
}

void die() {
	//AActor::Destroy();
}


