// Fill out your copyright notice in the Description page of Project Settings.


#include "SPlayerState.h"

bool ASPlayerState::AddCredits(float Delta)
{
	const float OldCredits = Credits;
	if(FMath::Abs(Delta) <= 0)
	{
		UE_LOG(LogTemp, Log, TEXT("AddCredits Delta <= 0"));
		return false;
	}

	Credits += Delta;
	UE_LOG(LogTemp, Log, TEXT("AddCredits Delta : %f, Credits : %f, NewCredits : %f"), Delta, OldCredits, Credits);
	return true;
}

bool ASPlayerState::HasEnoughCredits(float RequiredCredits) const
{
	UE_LOG(LogTemp, Log, TEXT("HasEnoughCredits Credits : %f, RequiredCredits : %f"), Credits, RequiredCredits);
	return Credits - RequiredCredits >= 0;
}