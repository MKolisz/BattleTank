// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possesing %s"), *(ControlledTank->GetName()));
	}

	if (!GetPlayerTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s did not recognize any player."), *(ControlledTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s recognized %s as a player."), *(ControlledTank->GetName()), *(GetPlayerTank()->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
