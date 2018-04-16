// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankNavMovementComponent.h"


void UTankNavMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet){

    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;

};

void UTankNavMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed){
    //    auto TankNAme = GetOwner()->GetName();
    //    auto MoveVelocityString = MoveVelocity.ToString();
    //    UE_LOG(LogTemp,Warning,TEXT("%s vectoring to %s"),*TankName,*MoveVelocityString);
    //
    auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    auto AIForwardIntention = MoveVelocity.GetSafeNormal();
    auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);

    intendMovementForward(ForwardThrow);

    auto RightThrow = FVector::CrossProduct(TankForward,AIForwardIntention).Z;
    MoveRightLeft(RightThrow);

};

void UTankNavMovementComponent::intendMovementForward(float throow){
  //  UE_LOG(LogTemp, Warning, TEXT("move forward throw %f "),throow);
    if(!LeftTrack || !RightTrack){return ;}
    LeftTrack->SetThortle(throow);
    RightTrack->SetThortle(throow);

};
void UTankNavMovementComponent::MoveRightLeft(float throow){
 //   UE_LOG(LogTemp, Warning, TEXT("move forward throw %f "),throow);
    if(!LeftTrack || !RightTrack){return ;}
    LeftTrack->SetThortle(throow);
    RightTrack->SetThortle(-throow);
    
};

