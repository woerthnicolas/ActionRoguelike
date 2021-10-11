// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "SitemBase.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASitemBase : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()
	
public:
	
	// Sets default values for this actor's properties
	ASitemBase();

protected:

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* StaticMeshComp;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
