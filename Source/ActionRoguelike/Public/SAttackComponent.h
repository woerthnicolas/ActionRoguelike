// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTIONROGUELIKE_API USAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void PrimaryAttack(TSubclassOf<AActor> AttackClass, FTransform Transform, float Timer);
	FTimerHandle TimerHandle_Attack;
	void Attack_TimerElapsed() const;
	
public:	
	// Sets default values for this component's properties
	USAttackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TSubclassOf<AActor> CurrentAttackClass;
	FTransform CurrentTransform;
	float CurrentTimer;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
