///<summary>
///@author Cathal Redmond
///</summary>

#include "character.h"

Character::Character(float t_intialHealth, 
					 float t_intialStrength, 
					 float t_intialDefense, 
					 float t_intialSpeed,
					 float t_intialEvasion, 
					 float t_intialattack,
					 float t_intialdamage,
					 int t_intialGold)
					 :
					 health{t_intialHealth},
					 strength{t_intialStrength},
					 defense{t_intialDefense},
					 speed{t_intialSpeed},
					 evasion{t_intialEvasion},
					 attackDamage{t_intialattack},
					 damage{t_intialdamage},
					 gold{ t_intialGold }
{
}

// function that adds a value to health (positive or minus value).
void Character::changeHealth(float t_changeInHealth)
{
	health += t_changeInHealth;
}

// function that sets health to chosen value.
void Character::setHealth(float t_newHealthValue)
{
	health = t_newHealthValue;
}

// function that returns health value.
float Character::getHealth() const
{
	return health;
}

// function that returns speed value.
float Character::getSpeed() const
{
	return speed;
}

// function that returns defense value.
float Character::getDefense() const
{
	return defense;
}

// function that calculates if evasion has occured and returns the bool.
bool Character::getEvasion() const
{
	// gets number between 1 and 100
	int randomNumber = rand() % 101 + 1;
	// if random number higher than evasion stat evasion occurs
	if (evasion < randomNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

// function that returns damage value.
float Character::getDamage() const
{

	return damage;
}

// function that returns strength value.
float Character::getStrength() const
{
	return strength;
}

// function that returns gold value.
int Character::getGold() const
{
	return gold;
}

// function that adds a value to the gold variable(positive or negative value).

void Character::changeGold(int t_changeInGold)
{
	gold += t_changeInGold;

}
// function that takes in values to determine which attack (spell, melee or shield to use)

void Character::attack(int t_typeNumber, 
					   int t_attackTypeNumber)
{
	//intialises these values each time a different attack occurs
	magicDamage = (rand() % 12) + 3;
	healing = false;
	shieldActive = false;
	attackDamage = 0;

	switch (t_typeNumber)
	{
	case 1:
		meleeAttack(t_attackTypeNumber);
		break;
	case 2:
		spellAttack(t_attackTypeNumber);
		break;
	case 3:
		shieldType(t_attackTypeNumber);
		break;
	default:
		break;
	}
	
}

// function that calculates damage value
void Character::calculateDamage(float t_enemyDefense)
{
	// damage is minus as when its added to enemy health its the same as subtracting
	damage = ((attackDamage + strength) - t_enemyDefense) * -1;
}

// function thats sets damage value
void Character::setDamage(float t_newDamage)
{
	damage = t_newDamage;
}

// function that checks and returns whether character is healing or not
bool Character::isHealing() const
{
	return healing;
}
// function that checks and returns whether character is shielded or not
bool Character::isShieldActive() const
{
	return shieldActive;
}

// functions that allows stats to be upgraded by constant amount
void Character::upgradeStats(int t_statType)
{
	switch (t_statType)
	{
	case 1:
		strength += 5;
	case 2:
		defense += 5;
	case 3:
		speed += 5;
	}
}

// function that sets attack damage if character is an enemy
void Character::enemyAttack()
{
	attackDamage = 10;
}

// function that determines attack damage based on spell chosen
// fifth option in switch statement allows for healing
void Character::spellAttack(int t_attackTypeNumber)
{
	switch (t_attackTypeNumber)
	{
	case 1:
		attackDamage = magicDamage;
		break;
	case 2:
		attackDamage = magicDamage;
		break;
	case 3:
		attackDamage = magicDamage;
		break;
	case 4:
		attackDamage = magicDamage;
		break;
	case 5:
		attackDamage = 0;
		healing = true;
		break;
	default:
		attackDamage = 0;
		break;
	}
}

// function that determines attack damage based on melee attack chosen
void Character::meleeAttack(int t_attackTypeNumber)
{
	switch (t_attackTypeNumber)
	{
	case 1:
		attackDamage = MEDIUM_DAMAGE;
		break;
	case 2:
		attackDamage = LIGHT_DAMAGE;
		break;
	case 3:
		attackDamage = MEDIUM_DAMAGE;
		break;
	case 4:
		attackDamage = LIGHT_DAMAGE;
		break;
	case 5:
		attackDamage = MEDIUM_DAMAGE;
		break;
	case 6:
		attackDamage = HEAVY_DAMAGE;
		break;
	case 7:
		attackDamage = HEAVY_DAMAGE;
		break;
	default:
		attackDamage = 0;
		break;
	}
}

// function that determines attack damage based on shield chosen
// first option in switch statement allow for shield to activate
void Character::shieldType(int t_attackTypeNumber)
{
	switch (t_attackTypeNumber)
	{
	case 1:
		shieldActive = true;
		break;
	case 2:
		attackDamage = magicDamage;
		break;
	case 3:
		attackDamage = MEDIUM_DAMAGE;
		break;
	default :
		break;
	}
}





