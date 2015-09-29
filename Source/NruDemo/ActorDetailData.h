// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"
#include "NruDemoCharacter.h"
#include "ActorDetailData.generated.h"

USTRUCT(BlueprintType)
struct NRUDEMO_API FDummyActorDetailData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	FDummyActorDetailData()
		: Attack(0.f)
		, HP(0.f)
		, Defense(0.f)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Detail)
	float HP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Detail)
	float Attack;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Detail)
	float Defense;
};
