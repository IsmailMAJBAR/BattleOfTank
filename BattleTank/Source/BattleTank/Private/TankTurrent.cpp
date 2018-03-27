// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurrent.h"

void UTankTurrent::Rotate(float RelativeSpeed){
   
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed,-1,+1) ;
    auto RotateChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds ;
    auto Rotation =  RelativeRotation.Yaw + RotateChange;
    SetRelativeRotation(FRotator(0,Rotation,0));
};
