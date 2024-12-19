// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SanitySystem.generated.h"

class USanityTracker;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMESYSTEMSCPP_API USanitySystem : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = SanityTracker, meta = (AllowPrivateAccess = "true"))
	USanityTracker* AC_sanityTracker;

public:	
	// Sets default values for this component's properties
	USanitySystem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	
	float radius;
	float otherRadius;
	float sanityEval;
	float currentSanity;

public:
	USanityTracker* GetOtherItem() { return AC_sanityTracker; };
	float GetSanity() { return currentSanity; }
	//Check if sanity tracker nearby
	void CheckNearbyTracker();
	//Check that tracker has value
	void VerifySanity(USanityTracker sanityTracker);
	//Set our sanity based on sanity tracker effect
	void SetSanity(USanityTracker sanityTracker);
};
