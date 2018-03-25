// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent),hidecategories =  ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    void Elevate(float DegreesPerSecond);
    
private:
    UPROPERTY(EditAnywhere,Category = Setup) float MaxDegreePerSecond = 20 ;
    UPROPERTY(EditAnywhere,Category = Setup) float MinElevation = 0 ;
    UPROPERTY(EditAnywhere,Category = Setup) float MaxElevation  = 40 ;

};