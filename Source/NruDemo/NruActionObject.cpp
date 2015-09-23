// Fill out your copyright notice in the Description page of Project Settings.

#include "NruDemo.h"
#include "NruActionObject.h"


// Sets default values
ANruActionObject::ANruActionObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANruActionObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANruActionObject::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

