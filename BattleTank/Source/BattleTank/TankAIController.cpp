// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay(){
    Super::BeginPlay();
    
    auto found=GetPlayerTank();
    if(found){
        UE_LOG(LogTemp,Warning,TEXT("AI tank found %s"), *(found->GetName()))
    }else{
        UE_LOG(LogTemp,Warning,TEXT("AI tank could not player tank"))
    }
}

ATank* ATankAIController::GetAITank() const{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const{
    auto playerPawn=GetWorld()->GetFirstPlayerController()->GetPawn();
    return Cast<ATank>(playerPawn);
}
