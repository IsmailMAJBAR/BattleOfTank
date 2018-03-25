// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingConponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingConponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingConponent();
    void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
    void AimAt(FVector HitLocation,float LunchSpeed);
    
private:
    UStaticMeshComponent* Barrel = nullptr;
    void MoveBarrel(FVector AimDirection);
};
