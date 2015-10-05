// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "GameFramework/GameMode.h"
#include "SpawnActorData.h"
#include "SpawnVolume.h"
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

	UPROPERTY(BlueprintReadWrite, category = "spawn")
	UDataTable * SpawnVolumeTable;

	UPROPERTY(BlueprintReadWrite, category = "spawn")
	UDataTable * SpawnActorTable;

	TArray<ASpawnVolume *> SpawnVolumeArray;

	UFUNCTION(BlueprintCallable, category = "spawn")
	void AddSpawnVolume(ASpawnVolume * SpawnVolume);

	UFUNCTION(BlueprintCallable, category = "spawn")
	void NotiySpawn(const FString & Name);

	UFUNCTION(BlueprintCallable, category = "spawn")
	void GetSpawnVolumeData(const FString & Name,UPARAM(ref) TArray<FSpawnVolumeData> & ArrSpawnVolume);

	UFUNCTION(BlueprintCallable, category = "spawn")
	void GetSpawnActorData(int32 Index, UPARAM(ref) FSpawnActorData & ActorData);
};
