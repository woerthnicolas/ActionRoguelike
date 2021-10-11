// Fill out your copyright notice in the Description page of Project Settings.


#include "SitemBase.h"

// Sets default values
ASitemBase::ASitemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
}

// Called when the game starts or when spawned
void ASitemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASitemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
