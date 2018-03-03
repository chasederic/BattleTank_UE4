// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
    
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController* EventInstiagtor, AActor* DamageCause){
    int32 damagePoints=FPlatformMath::RoundToInt(DamageAmount);
    int32 damageToApply=FMath::Clamp(damagePoints,0,currentHealth);
    currentHealth -= damageToApply;
    if(currentHealth <=0){
        UE_LOG(LogTemp, Warning, TEXT("Tank Died"))
    }
    return damageToApply;
}

float ATank::GetHealthPercent() const{
    return (float)currentHealth / (float)startingHealth;
}
