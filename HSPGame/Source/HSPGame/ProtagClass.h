// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#define D(x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT(x));} // Debug macro
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PaperFlipbookComponent.h"
#include "HSPGameGameModeBase.h"
#include "PaperCharacter.h"
#include "Base2DCharacter.h"
#include "Math/Rotator.h"
// No includes under this
#include "ProtagClass.generated.h"

UCLASS()
class HSPGAME_API AProtagClass : public ABase2DCharacter
{
	GENERATED_BODY()

public:
	// Constructor
	AProtagClass();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Functions 
	void moveRight(float axisValue);
	void moveForward(float axisValue);
	void resetRotation();

	// Class Properties
	/*UPROPERTY(EditAnywhere)
		UStaticMeshComponent * MyMesh;*/

	UPROPERTY(EditAnywhere)
		USpringArmComponent * CamBoom;

	UPROPERTY(EditAnywhere)
		UCameraComponent * Camera;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:


};
