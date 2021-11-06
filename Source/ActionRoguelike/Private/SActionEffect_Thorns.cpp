// Fill out your copyright notice in the Description page of Project Settings.


#include "SActionEffect_Thorns.h"

#include "SAttributeComponent.h"
#include "SCharacter.h"

USActionEffect_Thorns::USActionEffect_Thorns()
{

	
}

void USActionEffect_Thorns::StartAction_Implementation(AActor* Instigator)
{
	Super::StartAction_Implementation(Instigator);
	
	USAttributeComponent* AttributeComp = USAttributeComponent::GetAttributes(Instigator);
	if(AttributeComp)
	{
		AttributeComp->OnHealthChanged.AddDynamic(Instigator, )
	}
	
}

void USActionEffect_Thorns::StopAction_Implementation(AActor* Instigator)
{
	Super::StopAction_Implementation(Instigator);

	
}


void USActionEffect_Thorns::ExecuteEffect_Implementation(AActor* Instigator)
{
	
}