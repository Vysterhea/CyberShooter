// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class CYBERSHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;
	
	void MoveForward(float Value);
	void MoveSideways(float Value);
	void LookUpRate(float Value);
	void LookSidewaysRate(float Value);

	UPROPERTY(EditAnywhere, Category = "Movement")
	float RotationRate = 40;

	UPROPERTY()
	class AGun* Gun;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TSubclassOf<AGun> GunClass;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float MaxHealth = 100;
	UPROPERTY(VisibleAnywhere, Category = "Health")
	float CurrentHealth;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;
	UFUNCTION(BlueprintPure)
	bool IsAlive() const;
	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;
	
	void PullTrigger();

};
