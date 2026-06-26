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

	UE_LOG(LogTemp, Display, TEXT("Passed inspection."));


}

void UTBTTimer::Start()
{	
	FTimerHandle TestTimerHandle;
	World->GetTimerManager().SetTimer(
		TestTimerHandle,
		this,
		&UTBTTimer::Stop,
		TimerDuration,
		false
	);
}

void UTBTTimer::Stop()
{
	UE_LOG(LogTemp, Display, TEXT("Timer is done I think..."));
}

void UTBTTimer::Restart()
{

}
