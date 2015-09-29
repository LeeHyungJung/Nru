// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"
#include "NruDemoCharacter.h"
#include "SpawnActorData.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct NRUDEMO_API FSpawnActorData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	FSpawnActorData()
		: Level(0)
		, Type(ETypeEnum::None)
		, ObjectName("Dummy")
		, NruDemoChar(NULL)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
	FString ObjectName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
	ETypeEnum Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
	TSubclassOf<ANruDemoCharacter> NruDemoChar;
};

USTRUCT(BlueprintType)
struct NRUDEMO_API FSpawnVolumeData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	FSpawnVolumeData()
		: VolumeName("")
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
	FString VolumeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
	int32 Index;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
	int32 Position;
};