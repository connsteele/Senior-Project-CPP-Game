// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "HSPGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class HSPGAME_API UHSPGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	//Keep track of player exp between levels
	UPROPERTY(BlueprintReadWrite)
		float playerEXP;
	//Keep track of Player AP set by slider
	UPROPERTY(BlueprintReadWrite)
		float maxTurnAP = 300.f;

	//Keep track of Enemy damage scale KEPT NAME SO LESS CHANGES NEED TO BE MADE
	UPROPERTY(BlueprintReadWrite)
		float rangedEnemyDamage = 1.0f;

	//-- Base Damage for player, can be changed by talking to the scientist
	UPROPERTY(BlueprintReadWrite)
		float playerBaseDMG = 5.0f;

	//-- Max Possible Base Damage for player, limit for player customization
	UPROPERTY(BlueprintReadWrite)
		float EXplayerBaseDMG = 20.0f;

	//Bools for skills
	UPROPERTY(BlueprintReadWrite)
		bool isCastableFB = false; //fireball
	UPROPERTY(BlueprintReadWrite)
		bool isCastableLB = false; //lightning bolt

	//Possibly include this later
	//float health;


protected:

private:
	
};
