// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PaperFlipbookComponent.h"
#include "HSPGameGameModeBase.h"
#include "PaperCharacter.h"
#include "Base2DCharacter.h"
#include "Attacks.h"
#include "HSPGameInstance.h"
//#include "Kismet/GameplayStatics.h" 
#include "Math/Rotator.h"
// No includes under this
#include "ProtagClass.generated.h"

#define D(x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, x);} // Debug macro

UCLASS()
class HSPGAME_API AProtagClass : public ABase2DCharacter
{
	GENERATED_BODY()

public:
	// Constructor
	AProtagClass();

	//--- Override Functions
	UFUNCTION()
		virtual void inSight(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
		virtual void charHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	//UFUNCTION()
	virtual void Jump();

	UFUNCTION()
		void ReverseAnim();
	UFUNCTION()
		void turnOffJumping();
	
	// Blueprints for Attacks
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AAttacks> magicAttack;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AAttacks> atk_fireball;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AAttacks> atk_LightningBolt;

	UFUNCTION(BlueprintCallable) // Allow function below to be called by blueprint of this class
		void cursorClick();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//Polymorphic functions. Correct one called 
	virtual void startTurn();
	virtual void endTurn();


	void killEnemy(float gainedEXP);


	//--- Components
	UPROPERTY(EditAnywhere)
		USpringArmComponent * CamBoom;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		UCameraComponent * Camera;


	//--- Local Functions
	// Functions that move the player
	void moveRight(float axisValue);
	void moveForward(float axisValue);
	// Function Mapped to Rotate Camera + Action
	void RotateCamPlus();
	void RotateCamMinus();
	//UFUNCTION(BlueprintCallable)
	void Talk();

	//--- Local Variables
	UPROPERTY(BlueprintReadWrite)
		bool canAttack;
	UPROPERTY(BlueprintReadWrite)
		FString currentAttack;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool isInside;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool isInsideHorizontal;

	UPROPERTY(BlueprintReadOnly)
		float playerExp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:


};

