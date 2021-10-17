// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SBTTask_Heal.h"
#include "AIController.h"
#include "SAttributeComponent.h"
#include "Async/IAsyncTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"

EBTNodeResult::Type USBTTask_Heal::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* MyController = OwnerComp.GetAIOwner();
	if (ensure(MyController))
	{
		ACharacter* MyPawn = Cast<ACharacter>(MyController->GetPawn());
		if (MyPawn == nullptr)
		{
			return EBTNodeResult::Failed;
		}

		// Get USAttributeComponent
		USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(
			MyPawn->GetComponentByClass(USAttributeComponent::StaticClass()));

		if (ensure(AttributeComp))
		{
			AttributeComp->ApplyHealthChange(HealValue);
			UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
			if (ensure(BlackboardComp))
			{
				BlackboardComp->SetValueAsBool("LowHealth", false);
			}
			return EBTNodeResult::Succeeded;
		}

		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::Failed;
}
