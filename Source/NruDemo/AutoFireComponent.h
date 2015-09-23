// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "FireComponent.h"
#include "AutoFireComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NRUDEMO_API UAutoFireComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AutoFire)
	float FPS;

	float CurDeltaTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AutoFire)
	int32 MagazineCount;

	int32 CurMagazineCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AutoFire)
	float ReloadDelay;

	float CurReloadTime;

	UFireComponent * FireComp;

public:	
	// Sets default values for this component's properties
	UAutoFireComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UFUNCTION(BlueprintCallable, category = Fire)
	void SetFireComponent(UFireComponent * _FireComp);
	

private:
	void FireByFPS();

};
