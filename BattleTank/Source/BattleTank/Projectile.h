// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Classes/Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();
    
    virtual void BeginPlay() override;
    
    void LaunchProjectile(float launchSpeed);

private:
    UProjectileMovementComponent* projectileMovement=nullptr;
    
    UPROPERTY(VisibleAnywhere, Category="Component")
    UStaticMeshComponent* collisionMesh=nullptr;
    
    UPROPERTY(VisibleAnywhere, Category="Component")
    UParticleSystemComponent* launchBlast=nullptr;
    
    UPROPERTY(VisibleAnywhere, Category="Component")
    UParticleSystemComponent* impactBlast=nullptr;
    
    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	
};
