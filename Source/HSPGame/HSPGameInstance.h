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

	//Bools for skills
	UPROPERTY(BlueprintReadWrite)
		bool isCastableFB = false; //fireball

	//Possibly include this later
	//float health;


protected:

private:
	
};
