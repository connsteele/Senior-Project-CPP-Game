// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Base2DCharacter.h"
#include "EnemyClass.h"
//#include "EnemySlime.h"
#include "Containers/Array.h"
#include "HSPGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class HSPGAME_API AHSPGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	struct battleCharNode
	{
		ABase2DCharacter * charRef;
		FString className;
		bool isDead;

	};


	// Array of all characters currently in battle
	TArray<battleCharNode> battleChars;
	void addToBattle(ABase2DCharacter *addChar, FString className);

	//index of fighter whose turn it is
	int activeFighterIndex = 0;

	UPROPERTY(EditAnywhere)
		ABase2DCharacter * activeFighter = NULL;

	int aliveCharacters = 0;

	int get2DcharClassType(FString className);

	UFUNCTION(BlueprintCallable)
		void nextFighter();

	UFUNCTION(BlueprintCallable)
		ABase2DCharacter * getActiveFighter();

protected:

private:

};
