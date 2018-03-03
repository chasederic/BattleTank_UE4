// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Particles/ParticleSystemComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
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
    
    UPROPERTY(VisibleAnywhere, Category="Component")
    URadialForceComponent* explosionForce=nullptr;
    
    UPROPERTY(EditDefaultsOnly, Category="Setup")
    float destroyDelay=5.0;         //seconds
    
    UPROPERTY(EditDefaultsOnly, Category="Setup")
    float projectileDamage=1.0;        
    
    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	
    void OnTimerExpire();
};
