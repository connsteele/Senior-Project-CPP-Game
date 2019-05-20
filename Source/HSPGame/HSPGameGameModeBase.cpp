// Fill out your copyright notice in the Description page of Project Settings.

#include "HSPGameGameModeBase.h"


void AHSPGameGameModeBase::addToBattle(ABase2DCharacter * addChar, FString className)
{
	battleCharNode bpNode;
	bpNode.charRef = addChar;
	bpNode.className = className;
	bpNode.isDead = false;
	// Add the new character to the end of the battle array
	battleChars.Add(bpNode);
	//battleChars.Find(AProtagClass *, battleChIndex);
	// D("Battle Char Node added to the Battle Array");
}



int get2DcharClassType(FString className)
{
	if (className == "Protag")
	{
		// D("Protag");
		return 0;
	}
	return -1;
}

ABase2DCharacter * AHSPGameGameModeBase::getActiveFighter()
{
	return activeFighter;
}


void AHSPGameGameModeBase::nextFighter() {

	//Do out of bounds check before grabbing next fighter
	if (activeFighterIndex >= battleChars.Num()) {
		activeFighterIndex = 0;

		//Walk through array to clean dead characters

		int i = 0;

		while (i < battleChars.Num()) {
			if (battleChars[i].isDead) {
				// D("BOOM DEAD");
				battleChars.RemoveAt(i);
			}
			else {
				i++;
			}
		}
	}

	activeFighter = (battleChars[activeFighterIndex].charRef);


	//Check if actor is dead. If they are skip their turn
	if (activeFighter->currHealth <= 0) {
		battleChars[activeFighterIndex].isDead = true;
		activeFighterIndex++;
		nextFighter();
	}
	else {
		activeFighter->startTurn();

		activeFighterIndex++;
	}

	if (aliveCharacters == 1) {
		battleChars.Empty();
		ABase2DCharacter* protag = (ABase2DCharacter*)UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
		protag->isBattling = false;
		protag->isTurn = false;
		aliveCharacters = 0;
		activeFighterIndex = 0;
		return;
	}
}
