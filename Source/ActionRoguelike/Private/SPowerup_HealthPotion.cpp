// Fill out your copyright notice in the Description page of Project Settings.


#include "SPowerup_HealthPotion.h"
#include "SAttributeComponent.h"
#include "SPlayerState.h"


ASPowerup_HealthPotion::ASPowerup_HealthPotion()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	// Disable collision, instead we use SphereComp to handle interaction queries
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComp->SetupAttachment(RootComponent);
}


void ASPowerup_HealthPotion::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!ensure(InstigatorPawn))
	{
		return;
	}

	AController* Controller = Cast<AController>(InstigatorPawn->GetController());
	if(Controller)
	{
		ASPlayerState* PS = Controller->GetPlayerState<ASPlayerState>();
		if(PS)
		{
			if(PS->HasEnoughCredits(Cost))
			{
				USAttributeComponent* AttributeComp = USAttributeComponent::GetAttributes(InstigatorPawn);
				// Check if not already at max health
				if (ensure(AttributeComp) && !AttributeComp->IsFullHealth())
				{
					// Only activate if healed successfully
					if (AttributeComp->ApplyHealthChange(this, AttributeComp->GetHealthMax()))
					{
						HideAndCooldownPowerup();
						PS->AddCredits(-Cost);
					}
				}
			}
		}
	}
}
