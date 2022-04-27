// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlagStatusMessage.generated.h"

// Message indicating a Flag status change
USTRUCT(BlueprintType)
struct FLyraFlagStatusMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category=Gameplay)
	APawn* Instigator = nullptr;

	UPROPERTY(BlueprintReadWrite, Category=Gameplay)
	int32 FlagTeamId = 0;
	
	UPROPERTY(BlueprintReadWrite, Category=Gameplay)
	AActor* Pad = nullptr;
};