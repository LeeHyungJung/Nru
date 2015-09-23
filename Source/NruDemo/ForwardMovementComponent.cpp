// Fill out your copyright notice in the Description page of Project Settings.

#include "NruDemo.h"
#include "ForwardMovementComponent.h"

void UForwardMovementComponent::InitializeComponent()
{
	Super::InitializeComponent();

	MoveDirection = FVector(1.0f, 0.0f, 0.0f);

	ForwardMoveState = EForwardMovementComponentStateEnum::FE_Move;
}

void UForwardMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	switch (ForwardMoveState)
	{
	case EForwardMovementComponentStateEnum::FE_Move:
		{
			AddInputVector(MoveDirection, false);
		}
		break;
	case EForwardMovementComponentStateEnum::FE_Stop:
		{

		}
		break;
	case EForwardMovementComponentStateEnum::FE_ThrowBack:
		{
			if (IsMovingOnGround())
			{
				ForwardMoveState = EForwardMovementComponentStateEnum::FE_Move;
			}
		}
		break;
	}
}

void UForwardMovementComponent::Move()
{
	ForwardMoveState = EForwardMovementComponentStateEnum::FE_Move;
}

void UForwardMovementComponent::Stop()
{
	ForwardMoveState = EForwardMovementComponentStateEnum::FE_Stop;
}

void UForwardMovementComponent::OnThrowBack_Implementation(FVector InputDirection)
{
	ForwardMoveState = EForwardMovementComponentStateEnum::FE_ThrowBack;
	const FRotator rot(0, 45 * 180 / PI, 0);
	InputDirection = -1 * InputDirection;
	FVector result = rot.RotateVector(InputDirection);
	AddForce(result);
}
