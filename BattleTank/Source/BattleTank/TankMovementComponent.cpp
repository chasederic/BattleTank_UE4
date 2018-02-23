#include "TankMovementComponent.h"


void UTankMovementComponent::Initialize(UTrack* leftToSet, UTrack* rightToSet){
    leftTrack=leftToSet;
    rightTrack=rightToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& moveVelcity, bool bForceMaxSpeed){
    //no reason to call super as we are replacing functionality here
    auto aIForwardIntention = moveVelcity.GetSafeNormal();
    auto tankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    
    auto forwardMove = FVector::DotProduct(tankForward, aIForwardIntention); //moves like a cosine curve
    IntendMoveForward(forwardMove);
    
    auto rightMove =FVector::CrossProduct(tankForward, aIForwardIntention).Z;
    IntendMoveRight(rightMove);
    //UE_LOG(LogTemp, Warning, TEXT("%s vectoring to %s"), *tankName, *moveV)
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



