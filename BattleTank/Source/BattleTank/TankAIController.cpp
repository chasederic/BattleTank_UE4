// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay(){
    Super::BeginPlay();
}

void ATankAIController::Tick(float deltaTime){
    Super::Tick(deltaTime);
    
    auto playerTank=GetWorld()->GetFirstPlayerController()->GetPawn();
    auto aIControlledTank=GetPawn();
    if(!(ensure(playerTank) && ensure(aIControlledTank))){ return;}
    // move towards player. TODO check radius is in cm
    MoveToActor(playerTank,acceptableRadius);
        
    //Aim towards player
    auto aimingComponent = aIControlledTank->FindComponentByClass<UTankAimingComponent>();
    aimingComponent->AimAt(playerTank->GetActorLocation());
    
    if(aimingComponent->GetFiringState() == EFiringState::Locked){
        //fire if ready
        aimingComponent->Fire();
    }
}


