// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Item.h"
#include "Inventory.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Explorer.generated.h"

//Turn bool into FString
#define Q ?"True":"False"
UCLASS()
class LANDZONE_API AExplorer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AExplorer();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void MoveForward(float Scale);

	void MoveRight(float Scale);

	void LookUp(float Scale);

	void Turn(float Scale);

	void StartJumping();
	
	void StopJumping();

	void StartCrouching();
	
	void StopCrouching();

	void StartProning();
	
	void StopProning();

	void StartSprinting();

	void StopSprinting();

	UFUNCTION(BlueprintCallable)
	int32 GetInventoryCapacity();

	UFUNCTION(BlueprintCallable)
	void SetInventoryCapacity(int32 Capacity);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	int32 InventoryCapacity = 10;
	float Sensitivity = 50.f;
	UInventory* Inventory;
	
#define HotbarLength 9
	TArray<UItem, TFixedAllocator<HotbarLength>> Hotbar;

	UItem* HeldItem;
};
