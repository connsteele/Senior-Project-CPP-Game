// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "PaperFlipbookComponent.h"
#include "PaperCharacter.h"
#include "Math/Rotator.h"
#include "Base2DCharacter.generated.h"

UCLASS()
class HSPGAME_API ABase2DCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Sets default values for this character's properties
	ABase2DCharacter();

	// Booleans for animation
	bool isHorzMoving;
	bool isVertMoving;

	// Animations for the Class
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * idleAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * walkRightAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * walkForwardAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * walkDownAnim;

	// Functions 
	void moveRight();
	void moveForward();
	void resetRotation();
	//friend class ProtagClass; //Let protag class can direcly acces this classes vars

// Accessible by all derivations of this class
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

// Acessible only by this class
private:

	
};
