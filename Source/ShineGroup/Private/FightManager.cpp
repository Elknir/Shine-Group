#include "FightManager.h"

// Sets default values
AFightManager::AFightManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AFightManager::CombatStart(int BasePlayerHealth, int BaseEnemyHealth)
{
	CurrentEnemyHealth = BaseEnemyHealth;
	CurrentPlayerHealth = BasePlayerHealth;
	UpdateUI(CurrentPlayerHealth, CurrentEnemyHealth);
}


// Called when the game starts or when spawned
void AFightManager::BeginPlay()
{
	Super::BeginPlay();
}


 int32 AFightManager::CalculateDamage(int32 BaseDamage)
 {
	return FMath::RandRange(BaseDamage - 2, BaseDamage + 5);
}

void AFightManager::PlayerAttack()
{
	int32 Damage = CalculateDamage(10);
	ApplyDamage(CurrentEnemyHealth, Damage);

	if (CurrentEnemyHealth > 0)
	{
		PlayEnemyTurn();
	}
}

void AFightManager::PlayerFlee()
{
	//70% chance of ending the fight
	const float FleeChance = FMath::RandRange(0.0f, 1.0f);
	if(FleeChance > 0.3f) 
	{
		//Counts as a loose
		// Idea : make a neutral ending with an enum?
		OnFightFinished(false);
	}
	else
	{
	    //Failed To Escape
		PlayEnemyTurn();
	}
}


void AFightManager::PlayEnemyTurn()
{
	int32 Damage = CalculateDamage(5);
	ApplyDamage(CurrentPlayerHealth, Damage);
}

void AFightManager::ApplyDamage(int& TargetHealth, int Damage)
{
	//Not go below 0
	TargetHealth = FMath::Max(0, TargetHealth - Damage);

	// Apply visuals
	UpdateUI(CurrentPlayerHealth, CurrentEnemyHealth);

	// Check win conditions
	if (TargetHealth <= 0)
	{
		if (TargetHealth == CurrentPlayerHealth)
		{
			OnFightFinished(false);
		}
		else
		{
			OnFightFinished(true);
		}
	}
}




