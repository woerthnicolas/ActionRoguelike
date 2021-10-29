// Fill out your copyright notice in the Description page of Project Settings.


#include "SPowerupActor_Coin.h"

#include "SPlayerState.h"

ASPowerupActor_Coin::ASPowerupActor_Coin()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	// Disable collision, instead we use SphereComp to handle interaction queries
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComp->SetupAttachment(RootComponent);
}

void ASPowerupActor_Coin::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!ensure(InstigatorPawn))
	{
		return;
	}

	AController* Controller = Cast<AController>(InstigatorPawn->GetController());
	if (Controller)
	{
		ASPlayerState* PS = Controller->GetPlayerState<ASPlayerState>();
		if (PS)
		{
			PS->AddCredits(Grants);
			HideAndCooldownPowerup();
		}
	}
}
