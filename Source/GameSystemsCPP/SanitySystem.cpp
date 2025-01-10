// Fill out your copyright notice in the Description page of Project Settings.


#include "SanitySystem.h"
#include "SanityTracker.h"
#include <Kismet/GameplayStatics.h>
#include "GameFramework/Actor.h"

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
	SetComponentTickInterval(1.0);
	//Get all actors in scene
	TArray<AActor*> temp;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), temp);
	//Loop through array
	for (int i = 0; i <= temp.Num(); i++)
	{
		//Get any sanity tracker components
		if (temp[i]->GetComponentByClass<USanityTracker>())
		{
			//Keep them in sanity list
			ActorArray.Add(temp[i]);
		}
	}

	Super::BeginPlay();
}


// Called every frame
void USanitySystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	// ...

	//Check sanity list for radius
	CheckNearbyTracker();

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USanitySystem::CheckNearbyTracker()
{
	for (int i = 0; i <= ActorArray.Num(); i++)
	{
		if (ActorArray[i])
	}
}

bool USanitySystem::VerifySanity(USanityTracker* sanityTracker)
{
	float otherSanity;
	bool effect;

	if (otherSanity != NULL || 0 && effect != NULL)
	{
		return true;
	}
	else
		return false;
}

void USanitySystem::SetSanity(USanityTracker sanityTracker)
{
	float otherSanity;
	bool effect;
	bool check;

	check = VerifySanity(&sanityTracker);

	if (check == false)
		return;

	effect = sanityTracker.GetSanityEffect();
	otherSanity = sanityTracker.GetSanityAmount();

	if (effect == true)
	{
		currentSanity += otherSanity;
	}
	else if (effect == false)
	{
		currentSanity -= otherSanity;
	}
}

