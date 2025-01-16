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
		USanityTracker* variable = ActorArray[i]->GetComponentByClass<USanityTracker>();
		if (!IsValid(variable))
			return;

		if (FVector::Distance(GetOwner()->GetActorLocation(), variable->GetOwner()->GetActorLocation()) <= variable->GetRadius())
		{
			//Set Hit, Trace Start, and Trace End
			FHitResult Hit;
			FVector TraceStart = GetOwner()->GetActorLocation();
			FVector TraceEnd = variable->GetOwner()->GetActorLocation();

			//Set up QueryParams
			FCollisionQueryParams QueryParams;
			QueryParams.AddIgnoredActor(GetOwner());

			//Set Line Trace
			GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Visibility, QueryParams);

			if (Hit.bBlockingHit && IsValid(Hit.GetActor()->GetComponentByClass<USanityTracker>()))
			{
				USanityTracker* other = Hit.GetActor()->GetComponentByClass<USanityTracker>();
				bool positive = other->GetSanityEffect();
				if (positive)
				{
					currentSanity += other->GetSanityAmount();
				}
				else
					currentSanity -= other->GetSanityAmount();
			}
			else
				return;
		}

	}
}

bool USanitySystem::VerifySanity(USanityTracker* sanityTracker)
{
	float otherSanity = sanityTracker->GetSanityAmount();
	bool effect = sanityTracker->GetSanityEffect();

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

	if (effect == NULL)
		return;
	if (otherSanity <= 0 || NULL)
		return;

	if (effect == true)
	{
		currentSanity += otherSanity;
	}
	else
	{
		currentSanity -= otherSanity;
	}
}

