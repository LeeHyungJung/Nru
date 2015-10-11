// Fill out your copyright notice in the Description page of Project Settings.

#include "NruDemo.h"
#include "ForwardMovementComponent.h"

void UForwardMovementComponent::InitializeComponent()
{
	Super::InitializeComponent();

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

void UForwardMovementComponent::OnThrowBack(FVector InputDirection,int32 Force)
{
	if (ForwardMoveState != EForwardMovementComponentStateEnum::FE_ThrowBack)
	{
		ForwardMoveState = EForwardMovementComponentStateEnum::FE_ThrowBack;

		AddImpulse(InputDirection * Force);
	}
}