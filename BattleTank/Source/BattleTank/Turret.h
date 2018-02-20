// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Turret.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
    void Rotation(float relativeSpeed);
	
private:
    UPROPERTY(EditDefaultsOnly, Category=Setup)
    float MaxDegressPerSecond=25.0;
	
};
