// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankNavMovementComponent.h"

void UTankNavMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet){

    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;

};

void UTankNavMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed){
    auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    auto AIForwardIntention = MoveVelocity.GetSafeNormal();
    auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
    intendMovementForward(ForwardThrow);
    auto RightThrow = FVector::CrossProduct(TankForward,AIForwardIntention).Z;
    MoveRightLeft(RightThrow);

};

void UTankNavMovementComponent::intendMovementForward(float throow){
    if(!LeftTrack || !RightTrack){return ;}
    LeftTrack->SetThortle(throow);
    RightTrack->SetThortle(throow);
};
void UTankNavMovementComponent::MoveRightLeft(float throow){
    if(!LeftTrack || !RightTrack){return ;}
    LeftTrack->SetThortle(throow);
    RightTrack->SetThortle(-throow);
};


