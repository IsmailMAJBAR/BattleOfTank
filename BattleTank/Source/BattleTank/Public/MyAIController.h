// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API AMyAIController : public AAIController
{
	GENERATED_BODY()
    
    private:
    ATank* GetControlledTank() const ;
    virtual void BeginPlay() override;
    ATank* GetPlayerTank() const; // dose not change any thing
    virtual void Tick( float DeltaTime ) override;
};