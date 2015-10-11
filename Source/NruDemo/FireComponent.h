// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "NruActionObject.h"
#include "FireComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NRUDEMO_API UFireComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Action)
	TSubclassOf<ANruActionObject> ActionObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Action)
	float CoolTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Action)
	float CurCoolTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Action)
	bool CheckCoolTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Action)
	int32 Level;

public:	
	// Sets default values for this component's properties
	UFireComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UFUNCTION(BlueprintCallable, category = Fire)
	bool IsCoolTimeOver();

	UFUNCTION(BlueprintNativeEvent, category = Fire)
	void OnDoAction();

	virtual void OnDoAction_Implementation();
};
