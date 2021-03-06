// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "GameFramework/Actor.h"
#include "Engine.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	world = GetWorld();
	playerController = world->GetFirstPlayerController();

	UE_LOG(LogTemp, Warning, TEXT("Grabber checking in twice"))
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector outLoc;
	FRotator outRot;
	playerController->GetPlayerViewPoint(outLoc, outRot);
	//UE_LOG(LogTemp, Warning, TEXT("loc: %s, pos: %s"), *outLoc.ToString(), *outRot.ToString())

	FVector lineTraceEnd = outLoc + outRot.Vector()*200;

	DrawDebugLine(world, outLoc, lineTraceEnd, FColor(255, 0, 0), false, 0.f, 0.f, 10.f);

	//world->
}

