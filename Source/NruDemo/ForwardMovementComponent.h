// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/CharacterMovementComponent.h"
#include "ForwardMovementComponent.generated.h"


UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EForwardMovementComponentStateEnum : uint8
{
	FE_Move 		UMETA(DisplayName = "Move"),
	FE_Stop			UMETA(DisplayName = "Stop"),
	FE_ThrowBack 	UMETA(DisplayName = "ThrowBack"),
};
/**
 * 
 */
UCLASS()
class NRUDEMO_API UForwardMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MoveDirection)
	FVector MoveDirection;

	EForwardMovementComponentStateEnum ForwardMoveState;

public:
	UFUNCTION(BlueprintCallable, category = "ForwardMove")
	void Move();

	UFUNCTION(BlueprintCallable, category = "ForwardMove")
	void Stop();

	UFUNCTION(BlueprintCallable, category = "ForwardMove")
	void OnThrowBack(FVector InputDirection);

protected:
	//Init
	virtual void InitializeComponent() override;

	//Tick
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;


};
