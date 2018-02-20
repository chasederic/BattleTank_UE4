// Fill out your copyright notice in the Description page of Project Settings.

#include "Track.h"


void UTrack::SetThrottle(float throttle){
    //clamp throttle TODO
    auto forceApplied=GetForwardVector() * throttle * trackMaxForce;
    auto forceLocation=GetComponentLocation();
    auto tankRoot=Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    tankRoot->AddForceAtLocation(forceApplied,forceLocation);
}

