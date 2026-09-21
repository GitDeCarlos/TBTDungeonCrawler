// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHelloObject.h"
#include "Kismet/KismetSystemLibrary.h"

void UMyHelloObject::PrintHelloWorld()
{
	UKismetSystemLibrary::PrintString(
		this,
		TEXT("Hello World"),
		true,
		true,
		FLinearColor::Green,
		2.0f
	);
}
