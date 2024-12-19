// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SanityTracker.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMESYSTEMSCPP_API USanityTracker : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USanityTracker();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool GetSanityEffect() { return positiveSanity; }
	float GetSanityAmount() { return sanity; }
	float GetRadius() { return radius; }

private:
	bool positiveSanity = true;
	float sanity;
	float radius = 5;

private:
	void SetSanityEffect(bool effect) { positiveSanity = effect; }
	float SetSanity(float _sanity) { sanity = _sanity; return sanity; }
	float SetRadius(float _radius) { radius = _radius; return radius; }
};
