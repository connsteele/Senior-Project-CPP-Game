// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base2DCharacter.h"
#include "ArmsDealerClass.generated.h"

/**
 * 
 */
UCLASS()
class HSPGAME_API AArmsDealerClass : public ABase2DCharacter
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
		bool canTalk;
	// Override
	UFUNCTION()
		virtual void inSight(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
		virtual void outOfSight(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:

protected: 
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
