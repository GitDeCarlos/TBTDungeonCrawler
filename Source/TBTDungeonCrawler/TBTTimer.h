// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TBTTimer.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class TBTDUNGEONCRAWLER_API UTBTTimer : public UObject
{
	GENERATED_BODY()
	
public:
	UTBTTimer();

	UFUNCTION(BlueprintCallable)
	void Initialize(UObject* WorldContextObject, float InDuration, float InTickRate);

	UFUNCTION(BlueprintCallable)
	void Start();

	UFUNCTION(BlueprintCallable)
	void Stop();

	UFUNCTION(BlueprintCallable)
	void Restart();

	UPROPERTY(EditAnywhere)
	float TimerDuration;
	UPROPERTY(EditAnywhere)
	float TimerTickRate;

private:
	UWorld* World;
};
