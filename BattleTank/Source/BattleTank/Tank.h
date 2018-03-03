// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
    virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController* EventInstiagtor, AActor* DamageCause) override;
    
    //returns current health as a percentage of starting health
    UFUNCTION(BlueprintPure)
    float GetHealthPercent() const;
    
protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
private:
    // Sets default values for this pawn's properties
    ATank();
    
    UPROPERTY(EditDefaultsOnly, Category="Setup")
    int32 startingHealth=3;
    
    UPROPERTY(VisibleAnywhere, Category="Setup")
    int32 currentHealth=startingHealth;
};
