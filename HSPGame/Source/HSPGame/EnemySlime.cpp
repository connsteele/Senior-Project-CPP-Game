// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySlime.h"
#include "GameFramework/FloatingPawnMovement.h"
//#include "Camera/CameraComponent.h"

// Sets default values
AEnemySlime::AEnemySlime()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//// Make Pawn Movement Component
	//CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");

	//// Make a Mesh
	//Mesh = CreateDefaultSubobject<UStaticMeshComponent>("myMesh");

	//// Make a Spring Arm Attached to the Mesh
	//CamBoom = CreateDefaultSubobject<USpringArmComponent>("cameraBoom");
	//CamBoom->AttachTo(Mesh);

	//// Make a camera component and Attach it to the camera boom
	//Camera = CreateDefaultSubobject<UCameraComponent>("myCamera");
	//Camera->AttachTo(CamBoom);

}

// Called when the game starts or when spawned
void AEnemySlime::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemySlime::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemySlime::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//PlayerInputComponent->BindAxis("MoveForward", this, &AEnemySlime::moveForward);
	//PlayerInputComponent->BindAxis("MoveRight", this, &AEnemySlime::moveRight);
}

//void AEnemySlime::moveRight(float axisValue)
//{
//	if (axisValue == 1.0)
//	{
//		D("Right");
//	}
//	else if (axisValue == -1.0)
//	{
//		D("Left");
//	}
//	AddMovementInput(GetActorRightVector(), axisValue);
//}
//
//void AEnemySlime::moveForward(float axisValue)
//{
//	if (axisValue == 1.0)
//	{
//		D("Forward");
//	}
//	else if (axisValue == -1.0)
//	{
//		D("Down");
//	}
//
//	AddMovementInput(GetActorForwardVector(), axisValue);
//}

