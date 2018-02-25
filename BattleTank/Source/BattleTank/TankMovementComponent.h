// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Track.h"
#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * Responsible for driving the tank tracks
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category="Setup")
    void Initialize(UTrack* left, UTrack* right);
    
    UFUNCTION(BlueprintCallable, Category="Input")
    void IntendMoveForward(float move);
    
    UFUNCTION(BlueprintCallable, Category="Input")
    void IntendMoveRight(float move);
    
private:
    // called by tank ai controller's tick method: automatically by move to actor under the hood
    virtual void RequestDirectMove(const FVector& moveVelcity, bool bForceMaxSpeed) override;
    
    UTrack* rightTrack=nullptr;
    UTrack* leftTrack=nullptr;
};
