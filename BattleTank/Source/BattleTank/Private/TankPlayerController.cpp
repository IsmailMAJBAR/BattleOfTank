// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
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
        // UE_LOG(LogTemp,Warning,TEXT("HitLocation %s"),*HitLocation.ToString());
        GetControlledTank()->AimAt(HitLocation);
    }
}
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {
   // OutHitLocation = FVector(1.0); test
    int32 ViewPortSizeX;
    int32 ViewPortSizeY; //size of viewport
    GetViewportSize(ViewPortSizeX,ViewPortSizeY);
    auto ScreenLocation = FVector2D(ViewPortSizeX* CrossHairXLocation,ViewPortSizeY* CrossHairYLocation);
   // UE_LOG(LogTemp,Warning,TEXT("ScreenLocation %s"),*ScreenLocation.ToString());
    FVector lookDirection ;
    if(GetLoocDirection(ScreenLocation, lookDirection)){
       // UE_LOG(LogTemp,Warning,TEXT("WorldDirection %s"),*lookDirection.ToString());
        GetLookVectorHitLocation(lookDirection ,OutHitLocation);

    }
    return true ;
}
bool ATankPlayerController::GetLoocDirection(FVector2D ScreenLocation,FVector& lookDirection) const{
    FVector CameraWorldLocation ;
    FVector WorldDirection;
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation , lookDirection) ;
}
bool ATankPlayerController::GetLookVectorHitLocation(FVector lookDirection ,FVector& OutHitLocation) const{
    FHitResult HitResult ;
    auto StartLocation = PlayerCameraManager->GetCameraLocation();
    auto EndLocation = StartLocation +(lookDirection * LineTraceRange);
    if(GetWorld()->LineTraceSingleByChannel(HitResult,StartLocation,EndLocation,ECollisionChannel::ECC_Visibility)){
        OutHitLocation = HitResult.Location;
        return true ;
    }else{
        OutHitLocation = FVector(0.0);
        return false ;
    }
    
}
