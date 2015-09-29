// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "GameFramework/GameMode.h"
#include "SpawnActorData.h"
#include "NruDemoGameMode.generated.h"

// The GameMode defines the game being played. It governs the game rules, scoring, what actors
// are allowed to exist in this game type, and who may enter the game.
//
// This game mode just sets the default pawn to be the MyCharacter asset, which is a subclass of NruDemoCharacter

UCLASS(minimalapi)
class ANruDemoGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	ANruDemoGameMode();

	UFUNCTION(BlueprintNativeEvent, category = "Spawn")
	void GetSpawnVolumeData(UPARAM(ref) TArray<FSpawnVolumeData> & arr , const FString & Name);

	virtual void GetSpawnVolumeData_Implementation(UPARAM(ref) TArray<FSpawnVolumeData> & arr, const FString & Name);
/*

	UFUNCTION(BlueprintNativeEvent, category = "Spawn")
	void OnGetSpawnActorData(int32 Index, struct FSpawnActorData & data);

	virtual void OnGetSpawnActorData_Implementation(int32 Index, struct FSpawnActorData & data);*/
};
