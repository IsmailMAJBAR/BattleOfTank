// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "AIController.h"
#include "MyAIController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API AMyAIController : public AAIController
{
	GENERATED_BODY()
    
    private:
 //   ATank* GetControlledTank() const ;
    virtual void BeginPlay() override;
   // ATank* GetPlayerTank() const; // dose not change any thing
    virtual void Tick( float DeltaTime ) override;
    
    // How close can the AI tank get
    float AcceptanceRadius = 3000;

};
