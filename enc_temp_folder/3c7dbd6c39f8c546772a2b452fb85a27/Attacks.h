// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
// No Includes beneath here
#include "Attacks.generated.h"

UCLASS()
class HSPGAME_API AAttacks : public AActor
{
	GENERATED_BODY()
	
public:
	AAttacks(); // Sets default values for this actor's properties

	//--- Attack Collider
	UPROPERTY(EditAnywhere)
		USphereComponent * atkHitBox;

	UPROPERTY(EditAnywhere)
		float atkDamage; // How much the attack does to health on hit
	UPROPERTY(EditAnywhere)
		float apCost; // How much the attack costs to use

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void hitCharacter(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit);

	// Function called when root component hits another component
	void hitCharacter();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
