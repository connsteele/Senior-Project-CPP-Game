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


	// Functions 
	void moveRight(float axisValue);
	void moveForward(float axisValue);
	void resetRotation();
	void startTurn();
	void endTurn();

	//--- Override Functions
	//UFUNCTION()
	//	void protagHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION()
		virtual void inSight(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
		virtual void charHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	void cursorClick();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// Class Properties
	/*UPROPERTY(EditAnywhere)
		UStaticMeshComponent * MyMesh;*/
	//--- Components
	UPROPERTY(EditAnywhere)
		USpringArmComponent * CamBoom;

	UPROPERTY(EditAnywhere)
		UCameraComponent * Camera;

	/*UPROPERTY(EditAnywhere)
		USphereComponent * CircCollider;*/


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:


};

