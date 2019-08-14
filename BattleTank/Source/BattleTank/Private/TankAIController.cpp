// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"
//Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank))
	{
		//This method will do some pathfanding magic and call RequestDirectMove method in TankMovementComponent
		MoveToActor(PlayerTank, AcceptanceRadius);

		//Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//Fire every frame
		ControlledTank->Fire();
	}
}

