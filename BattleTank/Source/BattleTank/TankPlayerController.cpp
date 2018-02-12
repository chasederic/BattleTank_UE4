// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay(){
    Super::BeginPlay();
    
    auto controlled=GetControlledTank();
    if(controlled){
        UE_LOG(LogTemp,Warning,TEXT("Player tank controlled by %s"), *(controlled->GetName()))
    }else{
        UE_LOG(LogTemp,Warning,TEXT("Player tank not controlled"))
    }
}

ATank* ATankPlayerController::GetControlledTank() const{
    return Cast<ATank>(GetPawn());
}

