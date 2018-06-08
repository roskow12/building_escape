// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"
//#include "Engine/TriggerVolume.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	AActor* actorThatOpens;

	UPROPERTY(VisibleAnywhere)
	float openAngle = 90.f;
	

	UPROPERTY(EditAnywhere)
	ATriggerVolume* pressurePlate;
		
	AActor* owner;
	
	void OpenDoor();
	void CloseDoor();
	bool shouldCloseDoor();
	float lastDoorOpenTime;
};
