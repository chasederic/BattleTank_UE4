// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;
    //no need to protect pointers since adding in constructor
    projectileMovement=CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
    projectileMovement->bAutoActivate=false;
}

void AProjectile::LaunchProjectile(float launchSpeed){
    projectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * launchSpeed);
    projectileMovement->Activate();
}


