// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "GameFramework/Character.h"
#include "Base2DCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "ProtagClass.h"
#include "EnemyClass.generated.h"



/**
 * 
 */
UCLASS()
class HSPGAME_API AEnemyClass : public ABase2DCharacter
{
	GENERATED_BODY()

public:
	// Constructor
	AEnemyClass();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float rewardExp; // Exp given for killing this character
	virtual void die(); // override the parent function
	virtual void takeDmg(float hitDmg); //ovveride parent function
	


protected:
	virtual void BeginPlay() override;



private:


	
};

