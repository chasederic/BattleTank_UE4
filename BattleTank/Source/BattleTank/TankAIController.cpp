// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay(){
    Super::BeginPlay();
}

void ATankAIController::Tick(float deltaTime){
    Super::Tick(deltaTime);
    
    auto playerTank=GetWorld()->GetFirstPlayerController()->GetPawn();
    auto aIControlledTank=GetPawn();
    if(!(playerTank && aIControlledTank)){ return;}
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

void ATankAIController::SetPawn(APawn* InPawn){
    Super::SetPawn(InPawn);
    if(InPawn)
    {
        auto possessedTank = Cast<ATank>(InPawn);
        if(!possessedTank){ return;}
        
        //subscribe ourlocal method to the tank's death event
        possessedTank->OnDeath.AddUniqueDynamic(this,&ATankAIController::OnPossessedTankDeath);
    }
}

void ATankAIController::OnPossessedTankDeath(){
    //no ensure because gets initialized during runtime
    if(!GetPawn()){ return; }
    GetPawn()->DetachFromControllerPendingDestroy();
}


