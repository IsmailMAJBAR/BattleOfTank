// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BattleTank.h"
#include "Components/ActorComponent.h"
#include "TankAimingConponent.generated.h"


//forward declaration
class UTankBarrel;
class UTankTurrent;
// hold barrel propreties and elevation
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingConponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingConponent();
    void SetBarrelReference(UTankBarrel* BarrelToSet);
    void SetTurrentReference(UTankTurrent* TurrentToSet);
    void AimAt(FVector HitLocation,float LunchSpeed);
    
private:
    UTankBarrel* Barrel = nullptr;
    UTankTurrent* Turrent = nullptr;
    void MoveBarrel(FVector AimDirection);
};
