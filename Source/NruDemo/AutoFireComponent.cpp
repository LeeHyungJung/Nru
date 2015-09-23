// Fill out your copyright notice in the Description page of Project Settings.

#include "NruDemo.h"
#include "AutoFireComponent.h"


// Sets default values for this component's properties
UAutoFireComponent::UAutoFireComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	FPS = 1.0f;

	CurDeltaTime = 0;

	MagazineCount = -1;

	CurMagazineCount = 0;

	ReloadDelay = 0.f;

	CurReloadTime = 0.f;
}


// Called when the game starts
void UAutoFireComponent::BeginPlay()
{
	Super::BeginPlay();

	CurMagazineCount = MagazineCount;
}


// Called every frame
void UAutoFireComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	
	CurDeltaTime += DeltaTime;

	if (MagazineCount <= 0)
	{
		FireByFPS();
	}
	else if (MagazineCount > 0 && CurMagazineCount > 0)
	{
		FireByFPS();
		CurMagazineCount--;
	}
	else if (MagazineCount > 0 && CurMagazineCount <= 0)
	{
		CurReloadTime += DeltaTime;

		if (CurReloadTime > ReloadDelay)
		{
			CurMagazineCount = MagazineCount;

			CurReloadTime = 0.f;
		}
	}

}

void UAutoFireComponent::SetFireComponent(UFireComponent * _FireComp)
{
	FireComp = _FireComp;
}

void UAutoFireComponent::FireByFPS()
{
	if (CurDeltaTime > FPS)
	{
		if (FireComp != NULL)
		{
			FireComp->OnDoAction();
		}

		CurDeltaTime = 0.f;
	}
}

