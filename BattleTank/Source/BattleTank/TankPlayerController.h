// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be last include, quirk UE4

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
    
    ATank* GetControlledTank() const;
    
    //barrel moves when the white box moves for an accurate shot
    void AimTowardCrosshair();
    
    bool GetSightRayLocation(FVector& HitLocation) const;
    
    bool GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const;
    
    bool GetLookVectorHitLocation(FVector lookdirection,FVector& hitLocation) const;
    
    UPROPERTY(EditAnywhere)
    float CrosshairXLocation=0.5;
    
    UPROPERTY(EditAnywhere)
    float CrosshairYLocation=0.3333;
    
    UPROPERTY(EditAnywhere)
    float range = 1000000;
    
public:
    virtual void BeginPlay() override;
    
    virtual void Tick(float deltaTime) override;
    

	
};
