// Fill out your copyright notice in the Description page of Project Settings.

#include "Track.h"

UTrack::UTrack(){
    PrimaryComponentTick.bCanEverTick=false;
}

//hit event not in blueprint
void UTrack::BeginPlay(){
    OnComponentHit.AddDynamic(this, &UTrack::OnHit);
}

void UTrack::SetThrottle(float throttle){
    currentThrottle=FMath::Clamp<float>(currentThrottle+throttle, -1, 1);;
}

void UTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
    DriveTrack();
    ApplySidewaysForce();
    currentThrottle=0;
}

void UTrack::DriveTrack(){
    auto forceApplied=GetForwardVector() * currentThrottle * trackMaxForce;
    auto forceLocation=GetComponentLocation();
    auto tankRoot=Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    tankRoot->AddForceAtLocation(forceApplied,forceLocation);
}

void UTrack::ApplySidewaysForce(){
    //calculate the slippage speed
    auto splippageSpeed=FVector::DotProduct(GetRightVector(), GetComponentVelocity());
    //work out the required acceleration this frame to correct
    auto deltaTime = GetWorld()->GetDeltaSeconds();
    auto correctionAcceleration= -splippageSpeed / deltaTime * GetRightVector();
    //calculate and apply sideways force using f=ma
    auto tankRoot=Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
    auto correctionForce = (tankRoot->GetMass() * correctionAcceleration) / 2; //divde b/c there are two tracks
    tankRoot->AddForce(correctionForce);
}



