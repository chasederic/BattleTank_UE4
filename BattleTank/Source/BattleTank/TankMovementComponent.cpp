// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"


void UTankMovementComponent::Initialize(UTrack* leftToSet, UTrack* rightToSet){
    leftTrack=leftToSet;
    rightTrack=rightToSet;
}

void UTankMovementComponent::IntendMoveForward(float move){
    if(!leftTrack || !rightTrack){return ;}
    leftTrack->SetThrottle(move);
    rightTrack->SetThrottle(move);
}

void UTankMovementComponent::IntendMoveRight(float move){
    if(!leftTrack || !rightTrack){return ;}
    leftTrack->SetThrottle(move);
    rightTrack->SetThrottle(-move);     //negative move = turn right
}



