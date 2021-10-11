// Fill out your copyright notice in the Description page of Project Settings.


#include "SHealthPotion.h"

#include "SAttributeComponent.h"
#include "SCharacter.h"

ASHealthPotion::ASHealthPotion()
{
	Health = 50.0f;
}

void ASHealthPotion::Interact_Implementation(APawn* InstigatorPawn)
{
	USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(
			InstigatorPawn->GetComponentByClass(USAttributeComponent::StaticClass()));

	if(AttributeComp && bInteractable)
	{
		if(AttributeComp->GetHealth() >= AttributeComp->GetMaxHealth()) return;

		bInteractable = false;
		
		AttributeComp->ApplyHealthChange(Health);

		StaticMeshComp->SetVisibility(false);
		
		GetWorldTimerManager().SetTimer(ReactivationTimer, this, &ASHealthPotion::Reactivate, ReactivationTime);
	}
}

void ASHealthPotion::Reactivate()
{
	StaticMeshComp->SetVisibility(true);

	bInteractable = true;
}

