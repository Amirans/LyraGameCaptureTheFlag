// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/LyraPlayerSpawningManagerComponent.h"
#include "CTF_PlayerSpawnManagerComponent.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERCTFRUNTIME_API UCTF_PlayerSpawnManagerComponent : public ULyraPlayerSpawningManagerComponent
{
	GENERATED_BODY()

protected:

	virtual AActor* OnChoosePlayerStart(AController* Player, TArray<ALyraPlayerStart*>& PlayerStarts) override;	
};
