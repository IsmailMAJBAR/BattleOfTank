// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BattleTank.h"
#include "Components/ActorComponent.h"
#include "TankAimingConponent.generated.h"

UENUM()
enum class EFiringState : uint8 {
    Reloading,
    Aiming,
    Locked
};

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
    UFUNCTION(BlueprintCallable, Category = "Setup" ) void Initialise(UTankBarrel* BarrelToSet, UTankTurrent* TurrentToSet);
//    void SetBarrelReference(UTankBarrel* BarrelToSet);
//    void SetTurrentReference(UTankTurrent* TurrentToSet);
    void AimAt(FVector HitLocation,float LunchSpeed);
    
    
protected:
    UPROPERTY(BlueprintReadOnly, Category = "State")
    EFiringState FiringState= EFiringState::Reloading;

private:
    UTankBarrel* Barrel = nullptr;
    UTankTurrent* Turrent = nullptr;
    void MoveBarrel(FVector AimDirection);
    

};
