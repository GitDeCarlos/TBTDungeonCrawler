// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/TimerHandle.h"
#include "TBTTimer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimerFinished);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FOnTimerTick,
	float, TimeElapsed
);

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class TBTDUNGEONCRAWLER_API UTBTTimer : public UObject
{
	GENERATED_BODY()
	
public:

	// Custom Event Dispatchers
	UPROPERTY(BlueprintAssignable)
	FOnTimerFinished OnTimerFinished;

	UPROPERTY(BlueprintAssignable)
	FOnTimerTick OnTimerTick;

	// Public Functions
	UFUNCTION(BlueprintCallable)
	void Initialize(UObject* WorldContextObject, float InDuration, float InTickRate);

	UFUNCTION(BlueprintCallable)
	void Start();

	UFUNCTION(BlueprintCallable)
	void Stop();

	UFUNCTION(BlueprintCallable)
	void Restart();

	UFUNCTION(BlueprintCallable)
	bool IsActive();

	// Public variables
	UPROPERTY(EditAnywhere)
	float TimerDuration;
	UPROPERTY(EditAnywhere)
	float TimerTickRate;

private:
	void Tick();

	// Timer specific variables
	UWorld* World;
	FTimerHandle TimerHandle;

	// Private variables
	float TimeElapsed;
	float TimeRemaining;
	bool IsTimerInfinite = false;
};
