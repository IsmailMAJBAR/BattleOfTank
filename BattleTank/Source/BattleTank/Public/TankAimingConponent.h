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
class AProjectile;

// hold barrel propreties and elevation
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingConponent : public UActorComponent
{
	GENERATED_BODY()

public:	
    UFUNCTION(BlueprintCallable, Category = "Setup" )
    void Initialise(UTankBarrel* BarrelToSet, UTankTurrent* TurrentToSet);
    
    void AimAt(FVector HitLocation);
    
    UFUNCTION(BlueprintCallable , Category =  "Firing")
    void Fire();

protected:

    UPROPERTY(BlueprintReadOnly, Category = "State")
    EFiringState FiringState= EFiringState::Reloading;
    
private:
    UTankAimingConponent();
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType,
                            FActorComponentTickFunction *ThisTickFunction) override;
    void MoveBarrel(FVector AimDirection);
    bool BarrelisMoving();

    UTankBarrel* Barrel = nullptr;
    UTankTurrent* Turrent = nullptr;
    
    UPROPERTY(EditDefaultsOnly, Category = "Firing")
    float LunchSpeed = 6000.0 ;
  
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    TSubclassOf<AProjectile> ProjectileBluePrint ;
    
    UPROPERTY(EditDefaultsOnly, Category = "Firing")
    float ReloadTimeInSeconds = 3.0;
    
    double LastFireTime = 0.0;

    FVector AimDirection;
  

};
