// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#define D(x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT(x));} // Debug macro
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
// No includes under this
#include "EnemySlime.generated.h"


UCLASS()
class HSPGAME_API AEnemySlime : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemySlime();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//// Functions 
	//void moveRight(float axisValue);
	//void moveForward(float axisValue);

	//// Class Properties
	//UPROPERTY(EditAnywhere)
	//	UStaticMeshComponent * Mesh;

	//UPROPERTY(EditAnywhere)
	//	USpringArmComponent * CamBoom;

	//UPROPERTY(EditAnywhere)
	//	UCameraComponent * Camera;

};
