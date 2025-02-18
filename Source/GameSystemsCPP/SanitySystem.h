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
	UFUNCTION()
	float GetSanity() { return currentSanity; }
	UFUNCTION()
	bool VerifySanity(USanityTracker* sanityTracker);
	

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
	float otherRadius;
	TArray<AActor*> ActorArray;
	float currentSanity = 100;
public:
	USanityTracker* GetTracker() { return AC_sanityTracker; };
	void SetSanity(USanityTracker sanityTracker);

	//Check if sanity tracker nearby, deduct/add sanity if close and in sight
	void CheckNearbyTracker();
};
