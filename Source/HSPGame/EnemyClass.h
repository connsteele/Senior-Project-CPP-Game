// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "GameFramework/Character.h"
#include "Base2DCharacter.h"
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

	
	


protected:
	virtual void BeginPlay() override;



private:


	
};

