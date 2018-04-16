// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingConponent.h"
#include "TankBarrel.h"
#include "TankTurrent.h"
#include "Projectile.h"
#include "TankNavMovementComponent.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
//    TankAimingConponent = CreateDefaultSubobject<UTankAimingConponent>(FName("AimingConponant"));
// //   TankNavMovementComponent = CreateDefaultSubobject<UTankNavMovementComponent>(FName("MovementConponant"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


//// Called to bind functionality to input
//void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
//{
//    Super::SetupPlayerInputComponent(InputComponent);
//
//}

void ATank::AimAt(FVector HitLocation){
    if(!TankAimingConponent){return;}
    TankAimingConponent->AimAt(HitLocation, LunchSpeed);
}

//void ATank::SetBarrelReference(UTankBarrel* BarrelToSet){
//    TankAimingConponent->SetBarrelReference(BarrelToSet);
//    Barrel = BarrelToSet;
//};
//
//void ATank::SetTurrentReference(UTankTurrent* TurrentToSet){
//    TankAimingConponent->SetTurrentReference(TurrentToSet);
//};

void ATank::Fire(){
    
//    auto Time = GetWorld()->GetTimeSeconds();
//     UE_LOG(LogTemp,Warning,TEXT("%f tank fire"),Time);
    bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds ;
  
    if(Barrel && isReloaded){
        auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBluePrint,
                                                              Barrel->GetSocketLocation(FName("ProjectileSocket")),
                                                              Barrel->GetSocketRotation(FName("ProjectileSocket")));
        Projectile->LunchProjectile(LunchSpeed);
        LastFireTime = FPlatformTime::Seconds();
    }
    
    
};



















