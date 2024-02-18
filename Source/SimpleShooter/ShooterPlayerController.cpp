// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	HUD = CreateWidget(this, HUDScreenClass);
	if(HUD)	HUD->AddToViewport();	
}

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
	HUD->RemoveFromViewport();

	if (bIsWinner)
	{
		AddScream(WinScreenClass);
	}
	else
	{
		AddScream(LoseScreenClass);		
	}	
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

void AShooterPlayerController::AddScream(const TSubclassOf<UUserWidget>& Screem)
{
	UUserWidget* Widget = CreateWidget(this, Screem);
	if (Widget)
	{
		Widget->AddToViewport();
	}
}

