// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Turret.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
    
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    void AimAt(FVector hitLocation);
    
    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference(UTankBarrel* barrelToSet);
    
    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetTurretReference(UTurret* turretToSet);
    
    UFUNCTION(BlueprintCallable, Category = firing)
    void Fire();
    
    UPROPERTY(EditDefaultsOnly, Category=Setup)
    TSubclassOf<AProjectile> projectile_BP;
    
    UPROPERTY(EditDefaultsOnly, Category=Firing)
    float launchSpeed = 158000;                     // default 1580 m/s, low end of reheinmetall 120 mmtank gun
                                                    // muzzle velocity - used on M1A1 abrams
    UPROPERTY(EditDefaultsOnly, Category=Firing)
    //pause in shooting in seconds
    float reloadTimeInSeconds=3.0;
    
    //local barrel reference for spawning projectile
    UTankBarrel* localBarrelRef=nullptr;
    
    //helps calculate if reload is done so tank can fire
    double lastFireTime=0;
    
protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    //tank delegates aiming
    UTankAimingComponent* tankAimingComponent = nullptr;
};
