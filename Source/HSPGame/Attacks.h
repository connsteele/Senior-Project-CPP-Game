// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "HSPGameInstance.h"
// No Includes beneath here
#include "Attacks.generated.h"

UCLASS()
class HSPGAME_API AAttacks : public AActor
{
	GENERATED_BODY()
	
public:
	AAttacks(); // Sets default values for this actor's properties

	//--- Attack Collider
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		USphereComponent * atkHitBox;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float radiusDarkWhirl = 50.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float radiusFireBall = 32.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float radiusLightningBolt = 20.0f;

	//UPROPERTY(EditAnywhere)
	//	float baseAtkDmg; // Base Damage, doesnt change between attack but player can change it
	UPROPERTY(EditAnywhere)
		float atkMultiplier; // Is multiplied by base damage for total damage to enemy, is changed between attacks and is unchangable by the player
	UPROPERTY(EditAnywhere)
		float apCost; // How much the attack costs to use

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void hitCharacter(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
