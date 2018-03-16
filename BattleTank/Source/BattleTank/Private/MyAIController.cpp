// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "MyAIController.h"

void AMyAIController::BeginPlay(){
    Super::BeginPlay();
    auto ControlledTank = GetControlledTank();
    if(!ControlledTank){
        UE_LOG(LogTemp,Warning,TEXT("AIControler isn't controling any tank"));
    }else{
        UE_LOG(LogTemp,Warning,TEXT("AIControler is controling the tank : %s "),*(ControlledTank->GetName()));
    }
}

ATank* AMyAIController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}
