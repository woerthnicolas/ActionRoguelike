// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SPowerupActor.h"
#include "SPowerupActor_Coin.generated.h"

class UStaticMeshComponent;


/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASPowerupActor_Coin : public ASPowerupActor
{
	GENERATED_BODY()
protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Credits")
	float Grants = 4.0f;
public:

	void Interact_Implementation(APawn* InstigatorPawn) override;


	ASPowerupActor_Coin();
};
