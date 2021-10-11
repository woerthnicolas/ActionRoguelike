// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SitemBase.h"
#include "SHealthPotion.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASHealthPotion : public ASitemBase
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Health;

	float ReactivationTime = 10.0f;
		
	FTimerHandle ReactivationTimer;

	bool bInteractable = true;
protected:
	virtual void Interact_Implementation(APawn* InstigatorPawn) override;

	void Reactivate();
		
	ASHealthPotion();
};
