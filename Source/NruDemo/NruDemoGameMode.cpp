// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "NruDemo.h"
#include "NruDemoGameMode.h"
#include "NruDemoCharacter.h"
#include "SpawnActorData.h"

ANruDemoGameMode::ANruDemoGameMode()
{
	// set default pawn class to our character
	DefaultPawnClass = ANruDemoCharacter::StaticClass();	
}

void ANruDemoGameMode::GetSpawnVolumeData_Implementation(UPARAM(ref)  TArray<FSpawnVolumeData> & arr , const FString & Name)
{
}


/*
void ANruDemoGameMode::OnGetSpawnActorData_Implementation(int32 Index, struct FSpawnActorData & data)
{
	
}
*/
