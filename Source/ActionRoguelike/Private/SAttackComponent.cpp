// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Actor.h"
#include "SAttackComponent.h"

#include "SAttackInterface.h"

void USAttackComponent::PrimaryAttack(TSubclassOf<AActor> AttackClass, FTransform Transform, float Timer = 0.0f)
{
	if (AttackClass == nullptr || Timer == 0.0f) return;

	CurrentAttackClass = AttackClass;
	CurrentTransform = Transform;
	CurrentTimer = Timer;

	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle_Attack, this, &USAttackComponent::Attack_TimerElapsed,
		                                       Timer);
	}
}

void USAttackComponent::Attack_TimerElapsed() const
{
	AActor* MyOwner = GetOwner();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Instigator = GetOwner()->GetInstigator();
	AActor* SpawnedAttack = GetWorld()->SpawnActor<AActor>(CurrentAttackClass, CurrentTransform, SpawnParams);
	if (SpawnedAttack)
	{
		APawn* MyPawn = Cast<APawn>(MyOwner);
		if(MyPawn)
		{
			ISAttackInterface::Execute_Attack(SpawnedAttack, MyPawn);
		}
	}
}

// Sets default values for this component's properties
USAttackComponent::USAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void USAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
