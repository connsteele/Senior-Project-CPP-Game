// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "PaperCharacter.h"
#include "Math/Rotator.h"
//#include "Materials/Material.h"
#include "Components/SphereComponent.h"
#include "Base2DCharacter.generated.h"

#define D(x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, x);} // Debug macro


UCLASS()
class HSPGAME_API ABase2DCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABase2DCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	//--- Combat Components, Functions, and Variables
	bool isBattling;
	UPROPERTY(EditAnywhere)
		USphereComponent * visionSphere;
	/*
	UFUNCTION()
		void onHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
		*/

	// Define UFUNCTION in the classes u want to use this
	void inSight(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	void charHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit);
	void getTurnDistance();

	// Movement Booleans
	bool isMoveable;
	
	// uses for animation
	bool isHorzMoving;
	bool isVertMoving;

	//Variables values for battle
	float currHealth;
	float maxHealth;
	float turnAP;
	float maxTurnAP;
	float attackCost;
	float distanceToAP;

	UPROPERTY(BlueprintReadWrite)
	bool isTurn;

	//Vector for last recorded location
	FVector lastRecordedLocation;

	// Animations for the Class
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * idleAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * walkRightAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * walkForwardAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * walkDownAnim;

	UPROPERTY(EditAnywhere, Category = SpriteMaterial)
		UMaterial* defaultMaterial;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SpriteMaterial)
		UMaterial* mirrorHMaterial;*/

	// Functions 
	void moveRight();
	void moveForward();
	//void resetRotation();
	void die();
	virtual void endTurn();
	virtual void startTurn();
	//friend class ProtagClass; //Let protag class can direcly acces this classes vars

// Accessible by all derivations of this class
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

// Acessible only by this class
private:

	
};
