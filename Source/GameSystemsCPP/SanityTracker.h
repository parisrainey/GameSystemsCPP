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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SanityTracker, meta = (AllowPrivateAccess = "true"))
	float sanity;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SanityTracker, meta = (AllowPrivateAccess = "true"))
	float radius = 5;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SanityTracker, meta = (AllowPrivateAccess = "true"))
	bool positiveSanity;

	UFUNCTION()
	void SetSanityEffect(bool effect) { positiveSanity = effect; }
	UFUNCTION()
	float SetSanity(float newSanity) { sanity = newSanity; return sanity; }
	UFUNCTION()
	float SetRadius(float newRadius) { radius = newRadius; return radius; }
	UFUNCTION()
	bool GetSanityEffect() { return positiveSanity; }
	UFUNCTION()
	float GetSanityAmount() { return sanity; }
	UFUNCTION()
	float GetRadius() { return radius; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
