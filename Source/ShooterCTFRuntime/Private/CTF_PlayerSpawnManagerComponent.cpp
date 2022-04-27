// Fill out your copyright notice in the Description page of Project Settings.


#include "CTF_PlayerSpawnManagerComponent.h"

#include "Player/LyraPlayerStart.h"
#include "Teams/LyraTeamSubsystem.h"
#include "NativeGameplayTags.h"

UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_LYRA_CaptureTheFlag_TeamOneSpawn, "Lyra.CaptureTheFlag.TeamOne");
UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_LYRA_CaptureTheFlag_TwoOneSpawn, "Lyra.CaptureTheFlag.TeamTwo");

AActor* UCTF_PlayerSpawnManagerComponent::OnChoosePlayerStart(AController* Player, TArray<ALyraPlayerStart*>& PlayerStarts)
{
	const ULyraTeamSubsystem* TeamSubsystem = GetWorld()->GetSubsystem<ULyraTeamSubsystem>();
	const int32 PlayerTeamId = TeamSubsystem->FindTeamFromObject(Player);

	if(PlayerTeamId == INDEX_NONE)
	{
		return nullptr;
	}

	FGameplayTag TeamSpawnTag = FGameplayTag::EmptyTag;

	switch(PlayerTeamId)
	{
	case 1:
		TeamSpawnTag = TAG_LYRA_CaptureTheFlag_TeamOneSpawn;
		break;
	case 2:
		TeamSpawnTag = TAG_LYRA_CaptureTheFlag_TwoOneSpawn;
		break;
		default:
			return nullptr;
		break;
	}
	
	for(ALyraPlayerStart* EachPlayerStart : PlayerStarts)
	{
		if(!EachPlayerStart->IsClaimed() && EachPlayerStart->GetGameplayTags().HasTag(TeamSpawnTag))
		{
			return EachPlayerStart;
		}
	}

	return nullptr;
}