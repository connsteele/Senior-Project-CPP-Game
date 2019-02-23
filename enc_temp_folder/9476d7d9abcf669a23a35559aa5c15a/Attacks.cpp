// Fill out your copyright notice in the Description page of Project Settings.

#include "Attacks.h"

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
	/*atkHitBox->OnComponentHit().RemoveDynamic(this, &AAttacks::hitCharacter);
	atkHitBox->OnComponentHit().AddDynamic(this, &AAttacks::hitCharacter);*/
	atkHitBox->SetGenerateOverlapEvents(true); // Generate overlap events
	atkHitBox->SetNotifyRigidBodyCollision(false); // Don't trigger rigid bodies 
}

void AAttacks::hitCharacter(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	// If the other actor is an enemy do damage
	/*if ((Cast<class AEnemyClass>(OtherActor) != NULL) && (Cast<UCapsuleComponent>(OtherComp)))
	{
		D("Attack hit an enemy");
	}*/
}

// Called every frame
void AAttacks::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

