// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankBarrel.h"
#include "Turret.h"
#include "Projectile.h"
#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UENUM()
enum class EFiringState : uint8
{
    Reloading,
    Aiming,
    Locked,
    NoAmmo
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
    void AimAt(FVector hitLocation);
    
    UFUNCTION(BlueprintCallable, Category = "Setup")
    void Initialize(UTankBarrel* barrelToSet, UTurret* turretToSet);
    
    UFUNCTION(BlueprintCallable, Category = "Firing")
    void Fire();
    
    EFiringState GetFiringState() const;
    
    UFUNCTION(BlueprintCallable, Category = "Firing")
    int GetRoundsLeft() const;
    
protected:
    UPROPERTY(BlueprintReadOnly, Category="Firing State")
    EFiringState firingState = EFiringState::Reloading;
               
    UPROPERTY(EditDefaultsOnly, Category="Firing")
    float launchSpeed = 158000;                     // default 1580 m/s, low end of reheinmetall 120 mmtank gun
                                                    // muzzle velocity - used on M1A1 abrams
    UPROPERTY(EditDefaultsOnly, Category="Setup")
    TSubclassOf<AProjectile> projectile_BP;
    
    UPROPERTY(EditDefaultsOnly, Category="Firing")
    //pause in shooting in seconds
    float reloadTimeInSeconds=3.0;
    
    //helps calculate if reload is done so tank can fire
    double lastFireTime=0;
               
    FVector aimDirection;
    
    int roundsLeft=3;
private:
    // Sets default values for this component's properties
    UTankAimingComponent();
    
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
    
    virtual void BeginPlay() override;
    
    UTankBarrel* barrel=nullptr;
    UTurret* turret=nullptr;
    
    void MoveBarrelTowards(FVector aimDirection);
    
    bool IsBarrelMoving();
};
