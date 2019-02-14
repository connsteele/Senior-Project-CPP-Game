// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySlime.h"

AEnemySlime::AEnemySlime() : AEnemyClass()
{
	// Set the slime's vision radius
	visionSphere->SetSphereRadius(120.f);
	//Setup vision hit
	visionSphere->OnComponentBeginOverlap.AddDynamic(this, &AEnemySlime::inSight);
}

void AEnemySlime::inSight(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	D("Slime hit");
	if ((Cast<AProtagClass>(OtherActor) != NULL) && (Cast<UCapsuleComponent>(OtherComp)) && (isBattling == false))
	{
		isBattling = true;
		AHSPGameGameModeBase* gameModeref = (AHSPGameGameModeBase*)GetWorld()->GetAuthGameMode();
		gameModeref->addToBattle(this, "Slime"); // maybe cast this to (ABase2DCharacter *)
		D("Slime Enters Battle");
	}
}
