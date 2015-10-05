// Fill out your copyright notice in the Description page of Project Settings.

#include "NruDemo.h"
#include "SpawnVolume.h"
#include "NruDemoGameMode.h"
#include "SpawnActorData.h"
#include "NruDemoCharacter.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
	SpawingRoot = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawn"));
	
	RootComponent = SpawingRoot;

	
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
}

void ASpawnVolume::BuildSpawnData()
{
	ANruDemoGameMode * mode = (ANruDemoGameMode *)GetWorld()->GetAuthGameMode();

	mode->GetSpawnVolumeData(Name, VolumeDataArray);
}

void ASpawnVolume::OnSpawnActor()
{
	ANruDemoGameMode * mode = (ANruDemoGameMode *)GetWorld()->GetAuthGameMode();

	UWorld* const World = GetWorld();

	TArray<USceneComponent *> positions;

	SpawingRoot->GetChildrenComponents(true, positions);

	positions.Reserve(positions.Num());

	for (size_t i = 0; i < VolumeDataArray.Num(); ++i)
	{
		FSpawnVolumeData & volumeData = VolumeDataArray[i];

		FSpawnActorData actorData;

		mode->GetSpawnActorData(volumeData.Index, actorData);

		if (positions.Num() > volumeData.Position && positions[volumeData.Position] != nullptr)
		{
			USceneComponent * Comp = positions[volumeData.Position];

			FVector pos = Comp->GetComponentLocation();

			FRotator rot = Comp->GetComponentRotation();

			if (actorData.NruDemoChar)
			{
				ANruDemoCharacter * newActor = World->SpawnActor<ANruDemoCharacter>(actorData.NruDemoChar, pos, rot);

				newActor->TypeEnum  = actorData.Type;
				newActor->CharLevel = actorData.Level;
				newActor->CharName = actorData.ObjectName;
			}
		}
	}
}

