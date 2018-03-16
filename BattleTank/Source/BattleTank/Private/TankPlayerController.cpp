// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay(){
    Super::BeginPlay();
    auto ControlledTank = GetControlledTank();
    if(!ControlledTank){
        UE_LOG(LogTemp,Warning,TEXT("PlayerControler isn't controling any tank"));
    }else{
        UE_LOG(LogTemp,Warning,TEXT("PlayerControler is controling the tank : %s "),*(ControlledTank->GetName()));
    }
    
}
// Called every frame
void ATankPlayerController::Tick( float DeltaTime ){
    Super::Tick( DeltaTime );
    //UE_LOG(LogTemp,Warning,TEXT("PlayerControler tick"));
    AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair(){
    if(!GetControlledTank()){return;}
    FVector HitLocation ; //out parameter
    if(GetSightRayHitLocation(HitLocation)){
         //UE_LOG(LogTemp,Warning,TEXT("HitLocation %s"),*HitLocation.ToString());
    }
}
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {
   // OutHitLocation = FVector(1.0); test
    int32 ViewPortSizeX;
    int32 ViewPortSizeY; //size of viewport
    GetViewportSize(ViewPortSizeX,ViewPortSizeY);
    auto ScreenLocation = FVector2D(ViewPortSizeX* CrossHairXLocation,ViewPortSizeY* CrossHairYLocation);
    UE_LOG(LogTemp,Warning,TEXT("ScreenLocation %s"),*ScreenLocation.ToString());
    return true ;
}

