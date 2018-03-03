// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;
    
    collisionMesh=CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
    SetRootComponent(collisionMesh);
    collisionMesh->SetNotifyRigidBodyCollision(true);
    collisionMesh->SetVisibility(false);             //sensible default to invisible, change in bp when testing
    
    launchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Launch Blast"));
    launchBlast->SetupAttachment(RootComponent);      //AttachToComponet could also be used
                                                      //but need FAttachmentTransformRules::KeepRElativeTransform parameter
    
    impactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("ImpactBlast"));
    impactBlast->SetupAttachment(RootComponent);
    impactBlast->bAutoActivate=false;
    
    explosionForce = CreateDefaultSubobject<URadialForceComponent>(FName("Explosion Force"));
    explosionForce->SetupAttachment(RootComponent);
    
    //no need to protect pointers since adding in constructor
    projectileMovement=CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
    projectileMovement->bAutoActivate=false;
}

void AProjectile::BeginPlay()
{
    Super::BeginPlay();
    collisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

void AProjectile::LaunchProjectile(float launchSpeed){
    projectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * launchSpeed);
    projectileMovement->Activate();
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
    launchBlast->Deactivate();
    impactBlast->Activate();
    explosionForce->FireImpulse();
    
    SetRootComponent(impactBlast);
    collisionMesh->DestroyComponent();              //destroys collision mesh
    
    //tarray parameters damages all actors in that area
    UGameplayStatics::ApplyRadialDamage(this,projectileDamage,GetActorLocation(),explosionForce->Radius,UDamageType::StaticClass(),TArray<AActor*>());
    
    FTimerHandle timer;
    GetWorld()->GetTimerManager().SetTimer(timer,this,&AProjectile::OnTimerExpire,destroyDelay,false);  //destorys object in world outliner
}

//delegator
void AProjectile::OnTimerExpire(){
    Destroy();
}


