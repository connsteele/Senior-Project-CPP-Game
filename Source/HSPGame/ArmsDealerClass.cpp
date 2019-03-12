// Fill out your copyright notice in the Description page of Project Settings.

#include "ArmsDealerClass.h"

// Called every frame
void AArmsDealerClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AArmsDealerClass::BeginPlay()
{
	Super::BeginPlay();

	canTalk = false;

	// Set up Collisions
	visionSphere->OnComponentBeginOverlap.AddDynamic(this, &AArmsDealerClass::inSight);
	visionSphere->OnComponentEndOverlap.AddDynamic(this, &AArmsDealerClass::outOfSight);

}

void AArmsDealerClass::inSight(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	canTalk = true;
}

void AArmsDealerClass::outOfSight(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	canTalk = false;
}


