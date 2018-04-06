// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankNavMovementComponent.h"


void UTankNavMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet){

    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;

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
