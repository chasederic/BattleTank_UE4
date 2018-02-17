// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"

void UTurret::Rotation(float relativeSpeed){
    if(relativeSpeed > 180){
        relativeSpeed = relativeSpeed*-1;
    }else if(relativeSpeed < -180){
        relativeSpeed = relativeSpeed*-1;
    }
    relativeSpeed= FMath::Clamp<float>(relativeSpeed,-1,+1);
    auto rotationChange=relativeSpeed * MaxDegressPerSecond * GetWorld()->DeltaTimeSeconds;
    auto rotation= RelativeRotation.Yaw + rotationChange;
    SetRelativeRotation(FRotator (0,rotation,0));
}

