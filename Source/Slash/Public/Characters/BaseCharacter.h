// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTypes.h"
#include "Interfaces/HitInterface.h"
#include "BaseCharacter.generated.h"

class UInputMappingContext;
class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;
class AItem;
class UAnimMontage;
class AWeapon;
class UAttributeComponent;

UCLASS()
class SLASH_API ABaseCharacter : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	UFUNCTION(BlueprintCallable)
	void SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Attack();
	virtual bool CanAttack();
	bool IsAlive();
	virtual void Die();
	virtual void HandleDamage(float DamageAmount);


	UFUNCTION(BlueprintCallable)
	virtual void AttackEnd();

	void PlayHitSound(const FVector& ImpactPoint);
	void PlayHitParticles(const FVector& ImpactPoint);


	/**
	* Play montage functions
	*/
	virtual void PlayAttackMontages();
	virtual void PlayGetHitMontage(const FName& SectionName);

	virtual void DirectionalHitReact(const FVector& ImpactPoint);

	UPROPERTY(VisibleAnywhere)
	AWeapon* EquippedWeapon;


	/**
	* Animation montages
	*/

	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* AttackMontage;

	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* GetHitMontage;

	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* DeathMontage;


	/**
	* Components
	*/
	UPROPERTY(VisibleAnywhere)
	UAttributeComponent* Attributes;

private:
	UPROPERTY(EditAnywhere, Category = Sounds)
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = VisualEffects)
	UParticleSystem* HitParticles;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
