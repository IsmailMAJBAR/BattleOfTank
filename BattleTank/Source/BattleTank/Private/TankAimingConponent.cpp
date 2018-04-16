// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurrent.h"
#include "TankBarrel.h"
#include "TankAimingConponent.h"


// Sets default values for this component's properties
UTankAimingConponent::UTankAimingConponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingConponent::Initialise(UTankBarrel* BarrelToSet, UTankTurrent* TurrentToSet){
    Barrel = BarrelToSet;
    Turrent = TurrentToSet;
};
//void UTankAimingConponent::SetBarrelReference(UTankBarrel* BarrelToSet){
//    if(!BarrelToSet){ return; }
//    Barrel = BarrelToSet;
//};
//
//void UTankAimingConponent::SetTurrentReference(UTankTurrent* TurrentToSet){
//    if(!TurrentToSet){ return; }
//    Turrent = TurrentToSet;
//};

void UTankAimingConponent::AimAt(FVector HitLocation, float LunchSpeed){
    if(!Barrel){return ;}
    FVector OutLunchVelocity;
    FVector StartLocation = Barrel->GetSocketLocation(FName("ProjectileSocket"));
    bool HaveSolutionAim = UGameplayStatics::SuggestProjectileVelocity(this,OutLunchVelocity,StartLocation,
                            HitLocation,LunchSpeed,false,0.f,0.f,ESuggestProjVelocityTraceOption::DoNotTrace);
    if(HaveSolutionAim){
        auto OurTankName = GetOwner()->GetName() ;
        auto AimDirection = OutLunchVelocity.GetSafeNormal();
      //  UE_LOG(LogTemp,Warning,TEXT("%s firing at %s"),*OurTankName,*AimDirection.ToString());
        MoveBarrel(AimDirection);
        //auto Time = GetWorld()->GetTimeSeconds();
       // UE_LOG(LogTemp,Warning,TEXT("%f Aim Solve Found"),Time);
    }else{
      //  auto Time = GetWorld()->GetTimeSeconds();
      //  UE_LOG(LogTemp,Warning,TEXT("%f no aim solution found %s"),Time);
    }
};
void UTankAimingConponent::MoveBarrel(FVector AimDirection){
    if(!Barrel || !Turrent){return;};
    auto BarrelRotation = Barrel->GetForwardVector().Rotation();
    auto AimAsRotation = AimDirection.Rotation();
    auto DeltaRotation = AimAsRotation - BarrelRotation;
   // UE_LOG(LogTemp,Warning,TEXT("AimAsRotation at %s"),*AimAsRotation.ToString());
    Barrel->Elevate(DeltaRotation.Pitch);
    Turrent->Rotate(DeltaRotation.Yaw);
};
