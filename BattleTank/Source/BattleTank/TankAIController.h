// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"
// Depends on movement component via pathfinding system

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
    virtual void BeginPlay() override;
    
    virtual void Tick(float deltaTime) override;
    
    virtual void SetPawn(APawn* InPawn) override;
    
    UFUNCTION()
    void OnPossessedTankDeath();
 
protected:
    //how close the AI tank can come to player tank
    UPROPERTY(EditDefaultsOnly, Category="Setup")
    float acceptableRadius = 10000; // 200 meters
        	
};
