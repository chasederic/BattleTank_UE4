// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
    
    void AimAt(FVector hitLocation, float launchSpeed);
    
    // TODO add SetTurretReference
    
    void SetBarrelReference(UTankBarrel* barrel);
    
private:
    UTankBarrel* barrel=nullptr;
    
    void MoveBarrelTowards(FVector aimDirection);

};