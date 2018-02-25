// Fill out your copyright notice in the Description page of Project Settings.

#include "Track.h"

UTrack::UTrack(){
    PrimaryComponentTick.bCanEverTick=true;
}

void UTrack::SetThrottle(float throttle){
    //clamp throttle TODO
    auto forceApplied=GetForwardVector() * throttle * trackMaxForce;
    auto forceLocation=GetComponentLocation();
    auto tankRoot=Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    tankRoot->AddForceAtLocation(forceApplied,forceLocation);
}

void UTrack::TickComponent(float deltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction){
    Super::TickComponent(deltaTime,TickType,ThisTickFunction);
    //UE_LOG(LogTemp,Warning,TEXT("track ticking, tick tick tick"))
    //calculate the slippage speed
    auto splippageSpeed=FVector::DotProduct(GetRightVector(), GetComponentVelocity());
    //work out the required acceleration this frame to correct
    auto correctionAcceleration=-splippageSpeed / deltaTime * GetRightVector();
    //calculate and apply sideways force using f=ma
    auto tankRoot=Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
    auto correctionForce = (tankRoot->GetMass() * correctionAcceleration) / 2; //divde b/c there are two tracks
    tankRoot->AddForce(correctionForce);
}

