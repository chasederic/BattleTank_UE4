// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction){
    //UE_LOG(LogTemp,Warning,TEXT("Aiming Componenet ticking, tick tick tick"))
    
    if(roundsLeft<=0){
        firingState=EFiringState::NoAmmo;
    }else if((FPlatformTime::Seconds()-lastFireTime) < reloadTimeInSeconds){
        firingState=EFiringState::Reloading;
    }else if(IsBarrelMoving()){
        firingState=EFiringState::Aiming;
    }else{
        firingState=EFiringState::Locked;
    }
}

void UTankAimingComponent::BeginPlay(){
    //Super::BeginPlay();
    //so first fire is after inital reload
    lastFireTime=FPlatformTime::Seconds();
}

void UTankAimingComponent::Initialize(UTankBarrel* barrelToSet, UTurret* turretToSet){
    turret=turretToSet;
    barrel=barrelToSet;
}

bool UTankAimingComponent::IsBarrelMoving(){
    if(!ensure(barrel)){ return false;}
    auto barrelForward= barrel->GetForwardVector();
    return !barrelForward.Equals(aimDirection,0.01);
}

void UTankAimingComponent::AimAt(FVector hitLocation){
    if(!ensure(barrel)){ return;}
    FVector outLaunchVelocity;
    FVector startLocation = barrel->GetSocketLocation(FName("Projectile"));
    bool aimSolution=UGameplayStatics::SuggestProjectileVelocity(this,outLaunchVelocity,startLocation,hitLocation,launchSpeed,false,0,0,ESuggestProjVelocityTraceOption::DoNotTrace);
    if(aimSolution){
        aimDirection=outLaunchVelocity.GetSafeNormal();
        MoveBarrelTowards(aimDirection);
    }
    // if not solution don't do anything
}

void UTankAimingComponent::Fire(){
    
    if(firingState == EFiringState::Locked || firingState == EFiringState::Aiming ){
        //spawn projectile at the socket location on the barrel
        if(!ensure(barrel)){ return;}
        if(!ensure(projectile_BP)){ return;}
        auto projectile = GetWorld()->SpawnActor<AProjectile>(projectile_BP, barrel->GetSocketLocation(FName("Projectile")),barrel->GetSocketRotation(FName("Projectile")));
        projectile->LaunchProjectile(launchSpeed);
        lastFireTime=FPlatformTime::Seconds();
        roundsLeft--;
    }
}

EFiringState UTankAimingComponent::GetFiringState() const{
    return firingState;
}

int UTankAimingComponent::GetRoundsLeft() const{
    return roundsLeft;
}


void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection)
{
        if (!ensure(barrel) || !ensure(turret)) { return; }
        // Work-out difference between current barrel roation, and AimDirection
        auto barrelRotator = barrel->GetForwardVector().Rotation();
        auto aimAsRotator = aimDirection.Rotation();
        auto deltaRotator = aimAsRotator - barrelRotator;
    
        barrel->Elevate(deltaRotator.Pitch);
        turret->Rotation(deltaRotator.Yaw);
    
}      
