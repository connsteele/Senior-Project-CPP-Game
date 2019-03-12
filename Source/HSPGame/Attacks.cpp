// Fill out your copyright notice in the Description page of Project Settings.

#include "Attacks.h"
#define D(x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, x);} // Debug macro


// Sets default values
AAttacks::AAttacks()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set up a spherical hit box and set it as the root component
	atkHitBox = CreateDefaultSubobject<USphereComponent>("Atk Hit Box");
	RootComponent = atkHitBox;

}

// Called when the game starts or when spawned
void AAttacks::BeginPlay()
{
	Super::BeginPlay();
	
	//--- Setup functions for on hit
	atkHitBox->OnComponentBeginOverlap.RemoveDynamic(this, &AAttacks::hitCharacter);
	atkHitBox->OnComponentBeginOverlap.AddDynamic(this, &AAttacks::hitCharacter);
	atkHitBox->SetGenerateOverlapEvents(true); // Generate overlap events
	atkHitBox->SetNotifyRigidBodyCollision(true);
}

void AAttacks::hitCharacter(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	D("Attack hit a thing");
	// If the other actor is an enemy do damage
	if ((Cast<AEnemyClass>(OtherActor) != NULL) && (Cast<UCapsuleComponent>(OtherComp)))
	{
		D("Attack hit an enemy");
		AEnemyClass * enemRef = Cast<AEnemyClass>(OtherActor);
		enemRef->takeDmg(atkDamage);
	}
}

// Called every frame
void AAttacks::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

