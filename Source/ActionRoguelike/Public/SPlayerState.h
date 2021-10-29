// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASPlayerState : public APlayerState
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Credits")
	float Credits = 0;

public:
	UFUNCTION(BlueprintGetter)
	float GetCredits() const { return Credits; };

	UFUNCTION(BlueprintCallable)
	bool AddCredits(float Delta);

	UFUNCTION(BlueprintCallable)
	bool HasEnoughCredits(float RequiredCredits) const;
};
