// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
    
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    void AimAt(FVector hitLocation);
    
    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference(UTankBarrel* barrelToSet);
    
    UPROPERTY(EditAnywhere, Category=Firing)
    float launchSpeed = 158000;                     // 1580 m/s, low end of reheinmetall 120 mmtank gun
                                                    // muzzle velocity - used on M1A1 abrams
    
protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    //tank delegates aiming
    UTankAimingComponent* tankAimingComponent = nullptr;
};
