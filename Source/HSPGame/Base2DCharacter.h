// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "PaperCharacter.h"
#include "Math/Rotator.h"
//#include "Blueprint/WidgetLayoutLibrary.h"
//#include "Materials/Material.h"
#include "TimerManager.h"
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
	UPROPERTY(BlueprintReadOnly)
		bool isBattling;
	UPROPERTY(EditAnywhere)
		USphereComponent * visionSphere;
	/*
	UFUNCTION()
		void onHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
		*/

	// Define UFUNCTION in the classes u want to use this
	//UFUNCTION()
	void inSight(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	void charHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit);
	void getTurnDistance();

	
	// Combat Stat Related Variables
	bool isMoveable; // Movement Boolean
	UPROPERTY(BlueprintReadWrite)
		bool isTurn;
	float attackCost; // Basic Attack AP cost
	float distanceToAP; // Used as divisor to turn the length of distance moved into AP
	UPROPERTY(BlueprintReadOnly)
		float currHealth;
	UPROPERTY(BlueprintReadOnly)
		float maxHealth;
	UPROPERTY(BlueprintReadOnly)
		float turnAP;
	UPROPERTY(BlueprintReadOnly)
		float maxTurnAP;
	UPROPERTY(BlueprintReadOnly)
		float healthPercentage;
	UPROPERTY(BlueprintReadOnly)
		float APPercentage;
	FVector lastRecordedLocation; // Vector of last recorded location
	
	
	FTimerHandle JumpTimerHandle;
	FTimerHandle FallingTimerHandle;

	// Animations for the Class
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * idleAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * deathAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * walkLeftAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * walkRightAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * walkForwardAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * walkDownAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * FBjump;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		UPaperFlipbook * FBjumpIdle;


	// used for animation
	bool isHorzMoving;
	bool isVertMoving;
	bool isJumping;

	// Functions 
	void moveRight();
	void moveForward();
	virtual void die();
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
