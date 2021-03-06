// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    //-1 is max downward speed, and +1 is max up movement
    void Elevate(float relativeSpeed);
    
private:
    UPROPERTY(EditDefaultsOnly, Category="Setup")
    float MaxDegressPerSecond=10.0;
    
    UPROPERTY(EditDefaultsOnly, Category="Setup")
    float MaxElevation=40.0;
    
    UPROPERTY(EditDefaultsOnly, Category="Setup")
    float MinElevation=0.0;
	
	
	
};
