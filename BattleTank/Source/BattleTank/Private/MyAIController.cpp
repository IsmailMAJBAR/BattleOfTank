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
    auto PlayerTank = GetPlayerTank();
    if(!PlayerTank){
        UE_LOG(LogTemp,Warning,TEXT("AIControler didn't find player tank"));
    }else{
        UE_LOG(LogTemp,Warning,TEXT("AIControler did find player tank : %s "),*(PlayerTank->GetName()));
    }
}

ATank* AMyAIController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}
ATank* AMyAIController::GetPlayerTank() const{
    auto PlayerPawn  = GetWorld()->GetFirstPlayerController()->GetPawn();
    if(!PlayerPawn){return nullptr;}
    return Cast<ATank>(PlayerPawn) ;
    
}
