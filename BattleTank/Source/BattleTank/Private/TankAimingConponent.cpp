// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
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

void UTankAimingConponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet){
    Barrel = BarrelToSet;
};


// Called when the game starts
void UTankAimingConponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingConponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTankAimingConponent::AimAt(FVector HitLocation){
    auto OurTankName = GetOwner()->GetName() ;
    auto BarrelLocation = Barrel->GetComponentLocation().ToString();
    UE_LOG(LogTemp,Warning,TEXT("%s aiming at %s from %s"),*OurTankName,*HitLocation.ToString(),*BarrelLocation);
};
