// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingConponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    TankAimingConponent = CreateDefaultSubobject<UTankAimingConponent>(FName("AimingConponant"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation){
    TankAimingConponent->AimAt(HitLocation, LunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet){
    TankAimingConponent->SetBarrelReference(BarrelToSet);
};

void ATank::SetTurrentReference(UTankTurrent* TurrentToSet){
    TankAimingConponent->SetTurrentReference(TurrentToSet);
};

void ATank::Fire(){
    auto Time = GetWorld()->GetTimeSeconds();
     UE_LOG(LogTemp,Warning,TEXT("%f tank fire"),Time);
};
