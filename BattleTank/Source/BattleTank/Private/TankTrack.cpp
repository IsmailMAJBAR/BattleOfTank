// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"




void UTankTrack::SetThortle(float thortle){
   
    auto ForceApplied = GetForwardVector() * thortle * TrackMaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
    auto TankRoot = Cast<UPrimitiveComponent>( GetOwner()->GetRootComponent() );
    TankRoot->AddForceAtLocation(ForceApplied,ForceLocation);
};
