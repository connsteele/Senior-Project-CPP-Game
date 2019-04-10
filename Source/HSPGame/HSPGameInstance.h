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
