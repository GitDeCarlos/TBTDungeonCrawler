// Fill out your copyright notice in the Description page of Project Settings.


#include "TBTTimer.h"

UTBTTimer::UTBTTimer()
{
	UE_LOG(LogTemp, Display, TEXT("Constructor called.."));
}

void UTBTTimer::Initialize(UObject* WorldContextObject, float InDuration, float InTickRate)
{
	if (!WorldContextObject)
		return;

	World = WorldContextObject->GetWorld();
	if (!World)
		return;

	TimerDuration = InDuration;
	TimerTickRate = InTickRate;

	if (InDuration == 0.0f)
	{
		// Timer is infinite and duration should be ignored
		IsTimerInfinite = true;
	}

	UE_LOG(LogTemp, Display, TEXT("Passed inspection."));


}

void UTBTTimer::Start()
{	
	if (World->GetTimerManager().IsTimerActive(TimerHandle))
	{
		Restart();
		return;
	}

	TimeRemaining = TimerDuration;
	UE_LOG(LogTemp, Display, TEXT("TimeRemaining: %f"), TimeRemaining);
	TimeElapsed = 0;

	UE_LOG(LogTemp, Display, TEXT("Starting timer.."));
	World->GetTimerManager().SetTimer(
		TimerHandle,
		this,
		&UTBTTimer::Tick,
		TimerTickRate,
		true
	);
}

void UTBTTimer::Tick()
{
	OnTimerTick.Broadcast(TimeElapsed);

	TimeRemaining -= TimerTickRate;
	TimeElapsed += TimerTickRate;
	
	if (TimeRemaining <= 0.0f && !IsTimerInfinite)
	{
		OnTimerFinished.Broadcast();
		UE_LOG(LogTemp, Display, TEXT("Timer is completed"));
		Stop();
	}
}

void UTBTTimer::Stop()
{
	World->GetTimerManager().ClearTimer(TimerHandle);
	UE_LOG(LogTemp, Display, TEXT("Timer is stopped"));
}

void UTBTTimer::Restart()
{
	UE_LOG(LogTemp, Display, TEXT("Trying to restart..."));
	Stop();

	TimeRemaining = TimerDuration;
	TimeElapsed = 0;

	Start();
}

bool UTBTTimer::IsActive()
{
	return World->GetTimerManager().IsTimerActive(TimerHandle);
}
