// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyClass.h"
#include "GoblinSoldier.generated.h"

/**
 * 
 */
UCLASS()
class HSPGAME_API AGoblinSoldier : public AEnemyClass
{
	GENERATED_BODY()
	
public:
	AGoblinSoldier();


	virtual void inSight(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	void charHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit);


	virtual void Tick(float DeltaTime) override;

	//Overriden polymorphic functions
	virtual void endTurn();
	virtual void startTurn();

protected:
	virtual void BeginPlay() override;

};
