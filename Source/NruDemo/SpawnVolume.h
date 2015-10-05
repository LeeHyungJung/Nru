// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "SpawnActorData.h"
#include "SpawnVolume.generated.h"

UCLASS()
class NRUDEMO_API ASpawnVolume : public AActor
{
	GENERATED_BODY()

public:
	/** BoxComponent to specify the spawning area within the level. */
	UPROPERTY(VisibleInstanceOnly, Category = Spawn)
	UBoxComponent * SpawingRoot;

public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, category = "SpawnVolume")
	void BuildSpawnData();	

	UFUNCTION(BlueprintCallable, category = "SpawnVolume")
	void OnSpawnActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
	TArray<FSpawnVolumeData> VolumeDataArray;
};
