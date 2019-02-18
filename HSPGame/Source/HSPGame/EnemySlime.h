// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyClass.h"
#include "ProtagClass.h"
#include "GameFramework/Character.h"
#include "HSPGameGameModeBase.h"
#include "EnemySlime.generated.h"

// Macros
//#define D(x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT(x));} // Debug macro


/**
 * 
 */
UCLASS(Blueprintable)
class HSPGAME_API AEnemySlime : public AEnemyClass
{
	GENERATED_BODY()

public:
	AEnemySlime();

	UFUNCTION()
		virtual void inSight(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
		void charHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit);
	void BeginPlay();

	
	virtual void Tick(float DeltaTime) override;

	//Overriden polymorphic functions
	virtual void endTurn();
	virtual void startTurn();
};
