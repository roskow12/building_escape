// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReportStatue.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UPositionReportStatue::UPositionReportStatue()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReportStatue::BeginPlay()
{
	Super::BeginPlay();

	FString objectName = GetOwner()->GetName();
	FString objectPos = GetOwner()->GetTransform().GetLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("Position reporting for %s at location %s!"), *objectName, *objectPos);

	
}


// Called every frame
void UPositionReportStatue::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

