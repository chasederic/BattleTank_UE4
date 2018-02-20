// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay(){
    Super::BeginPlay();
}

void ATankAIController::Tick(float deltaTime){
    Super::Tick(deltaTime);
    
    auto playerTank=Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    auto controlledTank=Cast<ATank>(GetPawn());
    if(playerTank){
        // TODO move towards player
        
        //Aim towards player
        controlledTank->AimAt(playerTank->GetActorLocation());
        
        //fire if ready
       // controlledTank->Fire();
        
    }
    
}


