// Copyright Chase Deric & Udemy

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be last include, quirk UE4

/**
 * Responsible to help the player aim
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
    UFUNCTION(BlueprintImplementableEvent, Category="Setup")
    void FoundAimingComponent(UTankAimingComponent* aimCompRef);    //no implementation, blueprint event node
    
private:
    //barrel moves when the white box moves for an accurate shot
    void AimTowardCrosshair();
    
    bool GetSightRayLocation(FVector& HitLocation) const;
    
    bool GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const;
    
    bool GetLookVectorHitLocation(FVector lookdirection,FVector& hitLocation) const;
    
    UPROPERTY(EditDefaultsOnly)
    float CrosshairXLocation=0.5;
    
    UPROPERTY(EditDefaultsOnly)
    float CrosshairYLocation=0.3333;
    
    UPROPERTY(EditDefaultsOnly)
    float range = 1000000;
    
public:
    virtual void BeginPlay() override;
    
    virtual void Tick(float deltaTime) override;
    

	
};
