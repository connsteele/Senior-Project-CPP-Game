// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyClass.h"
#include "ProtagClass.h"

// Constructor
AEnemyClass::AEnemyClass() : ABase2DCharacter()
{
	pawnSensing = CreateDefaultSubobject<UPawnSensingComponent>("pawnSensing");
	
	// Set default enemy vision radius
	visionSphere->SetSphereRadius(200.f);
}

void AEnemyClass::BeginPlay()
{
	Super::BeginPlay();

	//--- Force enemies to face camera while moving
	bUseControllerRotationYaw = false;
	UCharacterMovementComponent * mover = GetCharacterMovement();
	mover->bOrientRotationToMovement = true;
	mover->RotationRate = FRotator(0, 0, 0);

	//--- Event Setup
	GetCapsuleComponent()->OnComponentHit.RemoveDynamic(this, &AEnemyClass::charHit);
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AEnemyClass::charHit);
	visionSphere->SetGenerateOverlapEvents(true);
	visionSphere->SetNotifyRigidBodyCollision(true);
	visionSphere->OnComponentBeginOverlap.RemoveDynamic(this, &AEnemyClass::inSight);
	visionSphere->OnComponentBeginOverlap.AddDynamic(this, &AEnemyClass::inSight);

	//--- Default Enemy Stat Related Variable Initialization
	maxHealth = 40.f;
	currHealth = maxHealth;
	maxTurnAP = 100.f;
	turnAP = maxTurnAP;
	distanceToAP = 10.f; // Used as divisor to turn the length of distance moved into AP, higher = more per turn movement
	isMoveable = true; // Allow actor to move
	rewardExp = 10;
	attackDMG = 10.f;

}

// Called every frame
void AEnemyClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyClass::die()
{
	Super::die();
	AProtagClass* player =  (AProtagClass*)UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	player->killEnemy(rewardExp);

}

//----- Turn Related Functions
void AEnemyClass::endTurn()
{
	Super::endTurn();
	isTurn = false;
	// D("Enemy Turn End");
}

void AEnemyClass::startTurn()
{
	// D("Enemy Turn Start");
	isTurn = true;
	// isBattling = true;
	turnAP = maxTurnAP; // Reset AP for new turn
	lastRecordedLocation = GetActorLocation();
}

// Called by when an attack hits an enemy
void AEnemyClass::takeDmg(float hitDmg)
{
	currHealth -= hitDmg;

	if (currHealth <= 0)
	{
		die();
	}
}

//----- Functions Bound For Collisions
// Called when the enemy slime's vision collider overlaps with a component
void AEnemyClass::inSight(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	// D("Enemy hit");
	if ((Cast<AProtagClass>(OtherActor) != NULL) && (Cast<UCapsuleComponent>(OtherComp)) && (isBattling == false))
	{
		isBattling = true;
		AHSPGameGameModeBase* gameModeref = (AHSPGameGameModeBase*)GetWorld()->GetAuthGameMode();
		gameModeref->addToBattle(this, "Enemy");
		// D("Slime Enters Battle");
	}
}

void AEnemyClass::charHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	if ((isTurn == true) && (Cast<AProtagClass>(OtherActor) != NULL) && (Cast<UCapsuleComponent>(OtherComp)))
	{
		//D("Hit Player");
		AProtagClass * playerRef = Cast<AProtagClass>(OtherActor);
		playerRef->currHealth -= attackDMG;
		endTurn();
	}
}


