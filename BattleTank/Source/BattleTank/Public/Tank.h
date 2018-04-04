// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//forward declaration
class UTankBarrel;
class UTankTurrent;
class UTankAimingConponent;
class AProjectile;
class UTankNavMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable,Category = Setup ) void SetBarrelReference(UTankBarrel* BarrelToSet);
    UFUNCTION(BlueprintCallable,Category = Setup ) void SetTurrentReference(UTankTurrent* TurrentToSet);
    void AimAt(FVector HitLocation);
    UFUNCTION(BlueprintCallable , Category =  Firing) void Fire();

    
protected:
    UTankAimingConponent* TankAimingConponent = nullptr ;
    
    UPROPERTY(BlueprintReadOnly) UTankNavMovementComponent* TankNavMovementComponent = nullptr ;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
    // Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
   
    UPROPERTY(EditDefaultsOnly, Category = Firing) float LunchSpeed = 6000.0 ;
    UPROPERTY(EditDefaultsOnly, Category = Setup) TSubclassOf<AProjectile> ProjectileBluePrint ;
    
    UTankBarrel* Barrel = nullptr;
    
    UPROPERTY(EditDefaultsOnly, Category = Firing) float ReloadTimeInSeconds = 3.0;
    double LastFireTime = 0.0;

};
