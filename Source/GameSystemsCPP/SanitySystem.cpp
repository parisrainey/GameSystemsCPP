// Fill out your copyright notice in the Description page of Project Settings.


#include "SanitySystem.h"
#include "SanityTracker.h"

// Sets default values for this component's properties
USanitySystem::USanitySystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USanitySystem::BeginPlay()
{
	// ...
	
}


// Called every frame
void USanitySystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	// ...
}

void USanitySystem::CheckNearbyTracker()
{
	if ()
}

void USanitySystem::VerifySanity(USanityTracker sanityTracker)
{

}

void USanitySystem::SetSanity(USanityTracker sanityTracker)
{

}

