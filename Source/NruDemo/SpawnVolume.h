// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "SpawnVolume.generated.h"

UCLASS()
class NRUDEMO_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, category = "SpawnVolume")
	void AddSpawnPosition(USceneComponent * comp);

	UFUNCTION(BlueprintCallable, category = "SpawnVolume")
	void OnSpawn();	

private:
	TArray<USceneComponent *> CompArray;
};
