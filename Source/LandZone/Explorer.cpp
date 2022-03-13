// Fill out your copyright notice in the Description page of Project Settings.


#include "Explorer.h"

// Sets default values
AExplorer::AExplorer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
	
	//TODO InventoryCapacity initialize
}

// Called when the game starts or when spawned
void AExplorer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExplorer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AExplorer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Axis setup
	PlayerInputComponent->BindAxis("MoveForward", this, &AExplorer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AExplorer::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AExplorer::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &AExplorer::Turn);

	//Action setup
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AExplorer::StartJumping);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AExplorer::StopJumping);
	
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AExplorer::StartCrouching);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AExplorer::StopCrouching);
	
	PlayerInputComponent->BindAction("Prone", IE_Pressed, this, &AExplorer::StartProning);
	PlayerInputComponent->BindAction("Prone", IE_Released, this, &AExplorer::StopProning);
	
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AExplorer::StartSprinting);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AExplorer::StopSprinting);
}

void AExplorer::MoveForward(float Scale)
{
	AddMovementInput(GetActorForwardVector(), Scale);
}

void AExplorer::MoveRight(float Scale)
{
	AddMovementInput(GetActorRightVector(), Scale);
}

void AExplorer::LookUp(float Scale)
{
	AddControllerPitchInput(Scale);
}

void AExplorer::Turn(float Scale)
{
	AddControllerYawInput(Scale);
}

void AExplorer::StartJumping()
{
	Super::Jump();
}

void AExplorer::StopJumping()
{
	Super::StopJumping();
}

void AExplorer::StartCrouching()
{
	Super::Crouch();
}

void AExplorer::StopCrouching()
{
	Super::UnCrouch();
}

void AExplorer::StartProning()
{
	
}

void AExplorer::StopProning()
{
	
}

void AExplorer::StartSprinting()
{
	
}

void AExplorer::StopSprinting()
{
	
}

int32 AExplorer::GetInventoryCapacity()
{
	return InventoryCapacity;
}

void AExplorer::SetInventoryCapacity(int32 Capacity)
{
	InventoryCapacity = Capacity;
	
	//TODO Edit inventory's capacity
}
