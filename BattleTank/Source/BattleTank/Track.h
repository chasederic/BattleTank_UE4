// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Track.generated.h"

/**
 * Track is used to set max driving force, and to apply forces to the tank.
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    //sets a throtle between -1, +1
    UFUNCTION(BlueprintCallable, Category="Input")
    void SetThrottle(float throttle);
    
    UPROPERTY(EditDefaultsOnly)
    float trackMaxForce=20000000.0; // 400,000m newtons of force
	
};
