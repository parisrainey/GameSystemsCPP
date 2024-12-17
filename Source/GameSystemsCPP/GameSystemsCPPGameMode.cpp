// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameSystemsCPPGameMode.h"
#include "GameSystemsCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameSystemsCPPGameMode::AGameSystemsCPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
