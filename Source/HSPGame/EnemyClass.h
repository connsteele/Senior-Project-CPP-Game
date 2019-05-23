// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "GameFramework/Character.h"
#include "Base2DCharacter.h"
#include "Perception/PawnSensingComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyClass.generated.h"




/**
 * 
 */
UCLASS()
class HSPGAME_API AEnemyClass : public ABase2DCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		UPawnSensingComponent * pawnSensing;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float attackDMG;

	// Constructor
	AEnemyClass();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float rewardExp; // Exp given for killing this character
	virtual void die(); // override the parent function
	virtual void takeDmg(float hitDmg); //ovveride parent function
	
	UFUNCTION()
		virtual void inSight(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
		void charHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit);
	virtual void endTurn();
	virtual void startTurn();

	bool isEnemyDead = false;


protected:
	virtual void BeginPlay() override;



private:


	
};

