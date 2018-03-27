// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//forward declaration
class UTankBarrel;
class UTankTurrent;
class UTankAimingConponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
    void AimAt(FVector HitLocation);
    UFUNCTION(BlueprintCallable,Category = Setup ) void SetBarrelReference(UTankBarrel* BarrelToSet);
    UFUNCTION(BlueprintCallable,Category = Setup ) void SetTurrentReference(UTankTurrent* TurrentToSet);
protected:
    UTankAimingConponent* TankAimingConponent = nullptr ;
    
private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
    // Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

    UPROPERTY(EditAnywhere, Category = Firing) float LunchSpeed = 100000.0 ;
	
};
