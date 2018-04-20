// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
//#include "Tank.h"
#include "TankAimingConponent.h"
#include "MyAIController.h"

void AMyAIController::BeginPlay(){
    Super::BeginPlay();
}
void AMyAIController::Tick( float DeltaTime ){
    Super::Tick( DeltaTime );
 
    auto PlayerTank  = GetWorld()->GetFirstPlayerController()->GetPawn();
    auto ControlledTank = GetPawn();
    if(!PlayerTank && !ControlledTank){ return;}
    auto AimingConponent = ControlledTank->FindComponentByClass<UTankAimingConponent>();
        // MOVE TOWARD THE PLAYER
        MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm
        //AIM AT THE PLAYER
        AimingConponent->AimAt(PlayerTank->GetActorLocation());
        //TODO Fix firing
    AimingConponent->Fire();
};
