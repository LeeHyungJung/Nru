// Fill out your copyright notice in the Description page of Project Settings.

#include "NruDemo.h"
#include "FireComponent.h"

// Sets default values for this component's properties
UFireComponent::UFireComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	CurCoolTime = 0.f;
	CoolTime	= 0.f;
	// ...

	CheckCoolTime = true;
}


// Called when the game starts
void UFireComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


// Called every frame
void UFireComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (CheckCoolTime == true)
	{
		if (IsCoolTimeOver() == false)
		{
			CurCoolTime += DeltaTime;
		}
	}
}

bool UFireComponent::IsCoolTimeOver()
{
	return CurCoolTime >= CurCoolTime;
}

void UFireComponent::OnDoAction_Implementation()
{
	if (CheckCoolTime && IsCoolTimeOver() == false)
	{
		return;
	}

	if (ActionObject != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World)
		{
			// Set the spawn parameters.
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = GetOwner();
			
			// Get a random location to spawn at.
			FVector SpawnLocation = GetComponentLocation();

			// Get a random rotation for the spawned item.
			FRotator SpawnRotation = GetComponentRotation();

			World->SpawnActor<AActor>(ActionObject, SpawnLocation, SpawnRotation, SpawnParams);
		}
	}

	if (CheckCoolTime)
	{
		CurCoolTime = 0.f;
	}
}

