// Copyright Chase Deric & Udemy

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay(){
    Super::BeginPlay();
}

void ATankPlayerController::Tick(float deltaTime){
    Super::Tick(deltaTime);
    AimTowardCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const{
    return Cast<ATank>(GetPawn());
}

//barrel moves when the white box moves for an accurate shot
void ATankPlayerController::AimTowardCrosshair(){
    if(!GetControlledTank()){
        return;
    }
    FVector hitLocation; // out parameter
    if(GetSightRayLocation(hitLocation)){
        GetControlledTank()->AimAt(hitLocation);
    }
}

//true if hits landscape
bool ATankPlayerController::GetSightRayLocation(FVector& hitLocation) const{
    //find the crosshair pixel coordinates
    int32 viewportSizeX, viewportSizeY;
    GetViewportSize(viewportSizeX, viewportSizeY);
    auto screenLocation = FVector2D(viewportSizeX * CrosshairXLocation,viewportSizeY * CrosshairYLocation);
    //"De-project" the screen position of the crosshair to a world direction
    FVector lookDirection;
    if(GetLookDirection(screenLocation,lookDirection)){
        //Line-trace
        return GetLookVectorHitLocation(lookDirection,hitLocation);
    }
    return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector lookdirection,FVector& hitLocation) const{
    FHitResult hitResult;
    auto start = PlayerCameraManager->GetCameraLocation();
    auto end = start + (lookdirection * range);
    if(GetWorld()->LineTraceSingleByChannel(hitResult,start,end,ECollisionChannel::ECC_Visibility)){
        hitLocation=hitResult.Location;
        return true;
    }
    hitLocation = FVector(0);
    return false;
}

//gets a unit vector of a location that the crosshairs are lookin at
bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const{
    FVector cameraWorldLocation; //unused but needed to pass into deprojecttoscreenpositiontoworld
    return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldLocation, lookDirection);
}
