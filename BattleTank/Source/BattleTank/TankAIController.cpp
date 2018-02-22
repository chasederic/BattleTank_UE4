// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay(){
    Super::BeginPlay();
}

void ATankAIController::Tick(float deltaTime){
    Super::Tick(deltaTime);
    
    auto playerTank=Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    auto aIControlledTank=Cast<ATank>(GetPawn());
    if(playerTank){
        // move towards player
        MoveToActor(playerTank,acceptableRadius);
        
        //Aim towards player
        aIControlledTank->AimAt(playerTank->GetActorLocation());
        
        //fire if ready
        aIControlledTank->Fire();
        
    }
    
}


