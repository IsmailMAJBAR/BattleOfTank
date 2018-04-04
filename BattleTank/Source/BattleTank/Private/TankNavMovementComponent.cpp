// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankNavMovementComponent.h"



void UTankNavMovementComponent::intendMovementForward(float throow){
    UE_LOG(LogTemp, Warning, TEXT("move forward throw %f "),throow);
};
