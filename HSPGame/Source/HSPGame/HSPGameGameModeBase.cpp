// Fill out your copyright notice in the Description page of Project Settings.

#include "HSPGameGameModeBase.h"

void AHSPGameGameModeBase::initEnemyTypes()
{
	// Push all enemy types onto this array
}

void AHSPGameGameModeBase::addToBattle(ABase2DCharacter * addCharRef)
{
	// Add the new character to the end of the battle array
	battleChars.Add(addCharRef);
}
