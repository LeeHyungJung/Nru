// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "NruDemo.h"
#include "NruDemoGameMode.h"
#include "NruDemoCharacter.h"
#include "SpawnActorData.h"
#include "Engine/DataTable.h"
#include "AssertionMacros.h"

ANruDemoGameMode::ANruDemoGameMode()
{
	// set default pawn class to our character
	DefaultPawnClass = ANruDemoCharacter::StaticClass();	
}

void ANruDemoGameMode::AddSpawnVolume(ASpawnVolume * SpawnVolume)
{
	SpawnVolumeArray.Add(SpawnVolume);
}

void ANruDemoGameMode::NotiySpawn(const FString & Name)
{
	for (ASpawnVolume * Volume : SpawnVolumeArray)
	{
		if (Volume->Name == Name)
		{
			Volume->OnSpawnActor();
		}
	}
}

void ANruDemoGameMode::GetSpawnVolumeData(const FString & Name, UPARAM(ref) TArray<FSpawnVolumeData> & ArrSpawnVolume)
{
	if (SpawnVolumeTable == nullptr) return;

	FString test = Name;

	//UE_LOG(LogTemp, Warning, TEXT(" server is unicode %s"), *test);

	TArray<FName> RowNames = SpawnVolumeTable->GetRowNames();

	for (size_t i = 0; i < RowNames.Num(); ++i)
	{
		FSpawnVolumeData * data = SpawnVolumeTable->FindRow<FSpawnVolumeData>(RowNames[i], "SpawnVolumeData");

		if (data != nullptr)
		{ 
			if (data->VolumeName == Name)
			{
				ArrSpawnVolume.Add(*data);
			}
		}
	}
}

void ANruDemoGameMode::GetSpawnActorData(int32 Index, UPARAM(ref) FSpawnActorData & ActorData)
{
	if (SpawnActorTable == nullptr) return;

	FString IntAsString = FString::FromInt(Index);

	FSpawnActorData * Data = SpawnActorTable->FindRow<FSpawnActorData>(FName(*IntAsString), "SpawnActorData");

	if (Data != nullptr)
	{
		ActorData = *Data;
	}
}

