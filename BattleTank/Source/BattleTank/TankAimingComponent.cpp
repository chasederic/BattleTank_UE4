// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* barrelToSet){
    //ptr check
    if(!barrelToSet){return;}
    barrel=barrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTurret* turretToSet){
    //ptr check
    if(!turretToSet){return;}
    turret=turretToSet;
}


void UTankAimingComponent::AimAt(FVector hitLocation, float launchSpeed){
    if(!barrel){
        return;
    }
    FVector outLaunchVelocity;
    FVector startLocation = barrel->GetSocketLocation(FName("Projectile"));
    bool aimSolution=UGameplayStatics::SuggestProjectileVelocity(this,outLaunchVelocity,startLocation,hitLocation,launchSpeed,false,0,0,ESuggestProjVelocityTraceOption::DoNotTrace);
    if(aimSolution){
        auto aimDirection=outLaunchVelocity.GetSafeNormal();
        MoveBarrelTowards(aimDirection);
    }
    // if not solution don't do anything
}

void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection)
{
        // Work-out difference between current barrel roation, and AimDirection
        auto barrelRotator = barrel->GetForwardVector().Rotation();
        auto aimAsRotator = aimDirection.Rotation();
        auto deltaRotator = aimAsRotator - barrelRotator;
    
        barrel->Elevate(deltaRotator.Pitch);
        turret->Rotation(deltaRotator.Yaw);
    
}      
