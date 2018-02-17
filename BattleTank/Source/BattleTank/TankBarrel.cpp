// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float relativeSpeed){
    // Move the barrel the right amount this frame
    // Given a max elevation speed, and the frame time
    relativeSpeed= FMath::Clamp<float>(relativeSpeed,-1,+1);
    auto elevationChange=relativeSpeed * MaxDegressPerSecond * GetWorld()->DeltaTimeSeconds;
    auto elevation= FMath::Clamp<float>((RelativeRotation.Pitch + elevationChange),MinElevation,MaxElevation);
    SetRelativeRotation(FRotator (elevation,0,0));
}

