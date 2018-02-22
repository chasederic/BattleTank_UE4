// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
    virtual void BeginPlay() override;
    
    virtual void Tick(float deltaTime) override;
    
    //how close the AI tank can come to player tank
    UPROPERTY(EditDefaultsOnly, Category=Setup)
    float acceptableRadius = 3000; // 30 meters
        	
};
