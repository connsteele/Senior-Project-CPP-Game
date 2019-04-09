// Fill out your copyright notice in the Description page of Project Settings.

#include "ScientistClass.h"

// Called every frame
void AScientistClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AScientistClass::BeginPlay()
{
	Super::BeginPlay();

	canTalk = false;

	// Set up Collisions
	visionSphere->OnComponentBeginOverlap.AddDynamic(this, &AScientistClass::inSight);
	visionSphere->OnComponentEndOverlap.AddDynamic(this, &AScientistClass::outOfSight);

}

void AScientistClass::inSight(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	canTalk = true;
}

void AScientistClass::outOfSight(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	canTalk = false;
}
