// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SBTService_CheckLowHealth.h"

#include "AIController.h"
#include "SAttributeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


void USBTService_CheckLowHealth::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (ensure(BlackboardComp))
	{
		// If LowHealth is already set, don't change anything
		if (BlackboardComp->GetValueAsBool("LowHealth"))
		{
			return;
		}

		AAIController* MyController = OwnerComp.GetAIOwner();
		if (ensure(MyController))
		{
			APawn* AIPawn = MyController->GetPawn();
			if (ensure(AIPawn))
			{
				// Get USAttributeComponent
				USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(
					AIPawn->GetComponentByClass(USAttributeComponent::StaticClass()));

				if (ensure(AttributeComp))
				{
					// If dead, no need to change the LowHealth key
					if (!AttributeComp->IsAlive())
					{
						return;
					}

					const bool bIsFullHealth = AttributeComp->IsFullHealth();
					
					BlackboardComp->SetValueAsBool(LowHealthKey.SelectedKeyName, !bIsFullHealth);
				}
			}
		}
	}
}
