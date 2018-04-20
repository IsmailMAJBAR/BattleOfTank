// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingConponent.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay(){
    Super::BeginPlay();

   auto AimingConponent = GetPawn()->FindComponentByClass<UTankAimingConponent>();
    if (AimingConponent){
        FoundAimingComponent(AimingConponent);
    }
}
// Called every frame
void ATankPlayerController::Tick( float DeltaTime ){
    Super::Tick( DeltaTime );
    //UE_LOG(LogTemp,Warning,TEXT("PlayerControler tick"));
    AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair(){
    auto AimingConponent = GetPawn()->FindComponentByClass<UTankAimingConponent>();
    if (AimingConponent){
        FoundAimingComponent(AimingConponent);
    }
    FVector HitLocation ; //out parameter
    if(GetSightRayHitLocation(HitLocation)){
       AimingConponent->AimAt(HitLocation);
    }
}
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {
    int32 ViewPortSizeX;
    int32 ViewPortSizeY; //size of viewport
    GetViewportSize(ViewPortSizeX,ViewPortSizeY);
    auto ScreenLocation = FVector2D(ViewPortSizeX* CrossHairXLocation,ViewPortSizeY* CrossHairYLocation);
    FVector lookDirection ;
    if(GetLoocDirection(ScreenLocation, lookDirection)){
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
