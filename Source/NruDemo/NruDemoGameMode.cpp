// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "NruDemo.h"
#include "NruDemoGameMode.h"
#include "NruDemoCharacter.h"

ANruDemoGameMode::ANruDemoGameMode()
{
	// set default pawn class to our character
	DefaultPawnClass = ANruDemoCharacter::StaticClass();	
}
