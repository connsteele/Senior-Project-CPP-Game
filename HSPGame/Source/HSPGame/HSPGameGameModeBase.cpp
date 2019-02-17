// Fill out your copyright notice in the Description page of Project Settings.

#include "HSPGameGameModeBase.h"
#define D(x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT(x));} // Debug macro


void AHSPGameGameModeBase::addToBattle(ABase2DCharacter * addChar, FString className)
{
	battleCharNode bpNode;
	bpNode.charRef = addChar;
	bpNode.className = className;
	bpNode.battleIndex = battleChars.Num();
	// Add the new character to the end of the battle array
	battleChars.Add(bpNode);
	//battleChars.Find(AProtagClass *, battleChIndex);
	D("Battle Char Node added to the Battle Array");
}



int get2DcharClassType(FString className)
{
	if (className == "Protag")
	{
		D("Protag");
		return 0;
	}
	return -1;
}


void AHSPGameGameModeBase::nextFighter() {

	ABase2DCharacter * activeFighter = (battleChars[activeFighterIndex].charRef);

	activeFighter->startTurn();

	activeFighterIndex++;

	if (activeFighterIndex == battleChars.Num() + 1) {
		activeFighterIndex = 0;
	}
}
