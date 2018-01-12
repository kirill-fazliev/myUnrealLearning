// Copyright Kirill 2018

#include "OpenDoor.h"
#include "GameFramework/Actor.h"



// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatsOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
	// Find OwnerActor
	AActor* Owner = GetOwner();
	// Creaate a rotator
	FRotator NewRotation = FRotator(0.f, -60.0f, 0.f);
	// get the door rotation
	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume
	// 
	if (PressurePlate)
	{
		if (PressurePlate->IsOverlappingActor(ActorThatsOpen))
		{
			OpenDoor();
		}
	}
}

