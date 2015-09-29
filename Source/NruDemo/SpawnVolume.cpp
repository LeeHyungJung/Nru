// Fill out your copyright notice in the Description page of Project Settings.

#include "NruDemo.h"
#include "SpawnVolume.h"
#include "NruDemoGameMode.h"
#include "SpawnActorData.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{

}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpawnVolume::AddSpawnPosition(USceneComponent * comp)
{
	CompArray.Add(comp);
}

void ASpawnVolume::OnSpawn()
{
	ANruDemoGameMode * mode = (ANruDemoGameMode *)GetWorld()->GetAuthGameMode();

	TArray<FSpawnVolumeData> arr;

	mode->GetSpawnVolumeData(arr,GetName());

	/*
	for (size_t i = 0; i < arr.Num(); ++i)
	{
		FSpawnVolumeData & data = arr[i];

		FSpawnActorData actorData;

		mode->OnGetSpawnActorData(data.Index, actorData);
	}*/
}

