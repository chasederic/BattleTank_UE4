// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    
    //no need to protect pointers since adding in constructor
    tankAimingComponent=CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector hitLocation){
    tankAimingComponent->AimAt(hitLocation,launchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* barrelToSet)
{
    tankAimingComponent->SetBarrelReference(barrelToSet);
    localBarrelRef=barrelToSet;
}

void ATank::SetTurretReference(UTurret* turretToSet)
{
    tankAimingComponent->SetTurretReference(turretToSet);
}

void ATank::Fire(){
    if(!localBarrelRef){ return; }
    //spawn projectile at the socket location on the barrel
    auto projectile = GetWorld()->SpawnActor<AProjectile>(projectile_BP, localBarrelRef->GetSocketLocation(FName("Projectile")),localBarrelRef->GetSocketRotation(FName("Projectile")));
    projectile->LaunchProjectile(launchSpeed);
    
}
