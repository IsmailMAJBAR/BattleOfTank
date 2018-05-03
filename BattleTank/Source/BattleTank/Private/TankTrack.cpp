// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"


UTankTrack::UTankTrack(){
    PrimaryComponentTick.bCanEverTick = true;
};

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType,
                                         FActorComponentTickFunction *ThisTickFunction){
//    Super::Tick( DeltaTime );


auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

    // Work-out the required acceleration this frame to correct
    auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

    // Calculate and apply sideways (F = m a)
   auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
    auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // Two tracks
    TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThortle(float thortle){
   
    auto ForceApplied = GetForwardVector() * thortle * TrackMaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
    auto TankRoot = Cast<UPrimitiveComponent>( GetOwner()->GetRootComponent() );
    TankRoot->AddForceAtLocation(ForceApplied,ForceLocation);
};
