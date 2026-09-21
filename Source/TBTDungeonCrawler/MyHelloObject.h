// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyHelloObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class TBTDUNGEONCRAWLER_API UMyHelloObject : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category="Hello Object")
	void PrintHelloWorld();
};
