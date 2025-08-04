// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FightManager.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SHINEGROUP_API AFightManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFightManager();

	UFUNCTION(BlueprintCallable, Category="Combat")
	void CombatStart(int BasePlayerHealth, int BaseEnemyHealth);

	UFUNCTION(BlueprintCallable, Category="Combat")
	void PlayerAttack();
    
	UFUNCTION(BlueprintCallable, Category="Combat")
	void PlayerFlee();

	//Maybe add a win count?
	UFUNCTION(BlueprintImplementableEvent, Category="Combat")
	void OnFightFinished(bool HasPlayerWon);

	UFUNCTION(BlueprintImplementableEvent, Category="Combat")
	void UpdateUI(int PlayerHealth, int EnemyHealth);



	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



private:
	void PlayEnemyTurn();
	void ApplyDamage(int& TargetHealth, int Damage);

	UFUNCTION(BlueprintPure, Category="Combat")
	static int32 CalculateDamage(int32 BaseDamage);

	
	int32 CurrentPlayerHealth;
	int32 CurrentEnemyHealth;
};
