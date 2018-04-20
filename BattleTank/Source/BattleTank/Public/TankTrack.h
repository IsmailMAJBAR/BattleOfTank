// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * tank track is used to test max driving force and apply forces to the tank
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable,Category = "Input" )  void SetThortle(float thortle);
    UPROPERTY(EditDefaultsOnly) float TrackMaxDrivingForce = 400000;
};
