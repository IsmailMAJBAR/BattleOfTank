// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurrent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingConponent.h"

// Sets default values for this component's properties
UTankAimingConponent::UTankAimingConponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingConponent::BeginPlay()
{
        // So that first first is after initial reload
        LastFireTime = FPlatformTime::Seconds();
}

void UTankAimingConponent::Initialise(UTankBarrel* BarrelToSet, UTankTurrent* TurrentToSet){
    Barrel = BarrelToSet;
    Turrent = TurrentToSet;
};

void UTankAimingConponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
                                FActorComponentTickFunction *ThisTickFunction){
        if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSeconds){
                FiringState = EFiringState::Reloading;
        }else if (BarrelisMoving()){
            FiringState = EFiringState::Aiming;
        }else{
            FiringState = EFiringState::Locked;
        }
}
bool UTankAimingConponent::BarrelisMoving(){
    if (!Barrel) { return false; }
        auto BarrelForward = Barrel->GetForwardVector();
        return !BarrelForward.Equals(AimDirection, 0.01); // vectors are equal

}

void UTankAimingConponent::AimAt(FVector HitLocation){
    if(!Barrel){return ;}
    FVector OutLunchVelocity;
    FVector StartLocation = Barrel->GetSocketLocation(FName("ProjectileSocket"));
    bool HaveSolutionAim = UGameplayStatics::SuggestProjectileVelocity(this,OutLunchVelocity,StartLocation,
                            HitLocation,LunchSpeed,false,0.f,0.f,ESuggestProjVelocityTraceOption::DoNotTrace);
    if(HaveSolutionAim){
        AimDirection = OutLunchVelocity.GetSafeNormal();
        MoveBarrel(AimDirection);
    }
};

void UTankAimingConponent::MoveBarrel(FVector AimDirection){
    if(!Barrel || !Turrent){return;};
    auto BarrelRotation = Barrel->GetForwardVector().Rotation();
    auto AimAsRotation = AimDirection.Rotation();
    auto DeltaRotation = AimAsRotation - BarrelRotation;
    Barrel->Elevate(DeltaRotation.Pitch);
    if (DeltaRotation.Yaw < 180){
        Turrent->Rotate(DeltaRotation.Yaw);
    }else{
        Turrent->Rotate(-DeltaRotation.Yaw);
            }
};

void UTankAimingConponent::Fire(){
        if (FiringState != EFiringState::Reloading){
            if (!Barrel){ return; }
            if (!ProjectileBluePrint){ return; }
            auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBluePrint,
                            Barrel->GetSocketLocation(FName("ProjectileSocket")),
                            Barrel->GetSocketRotation(FName("ProjectileSocket")));
            Projectile->LunchProjectile(LunchSpeed);
            LastFireTime = FPlatformTime::Seconds();
    }
};
