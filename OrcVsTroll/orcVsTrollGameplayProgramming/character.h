///<summary>
///@author Cathal Redmond
///</summary>

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>


// class for character 
//troll or orc
//player character or enemy npc
class Character
{
public:
	
	Character(float t_intialHealth = 0, 
			  float t_intialStrength = 0,
			  float t_intialDefense = 0,
			  float t_intialSpeed = 0,
			  float t_intialEvasion = 0,
			  float t_intialattack = 0,
			  float t_intialdamage = 0,
			  int t_intialGold = 0);

	virtual void changeHealth(float t_changeInHealth);
	virtual void setHealth(float t_newHealthValue);
	virtual float getHealth() const;
	virtual float getSpeed() const;
	virtual float getDefense() const;
	virtual bool getEvasion() const;
	virtual float getDamage() const;
	virtual float getStrength() const;
	virtual int getGold() const;
	virtual void changeGold(int t_changeInGold);
	virtual void attack(int t_typeNumber, 
						int t_attackTypeNumber);
	virtual void calculateDamage(float t_enemyDefense);
	virtual void setDamage(float t_newDamage);
	virtual bool isHealing() const;
	virtual bool isShieldActive() const;
	virtual void upgradeStats(int t_statType);
	virtual void enemyAttack();

	
	
protected:
	// protected member variable
	// how much health charcacter has
	float health;
	// strength of character
	float strength;
	// defense of character
	float defense;
	// speed of character (higher speed attacks first)
	float speed;
	// evasion of character
	float evasion;
	// how much base damage attack do
	float attackDamage;
	// full damage which adds attack and strength
	float damage;
	// how much gold character has
	int gold;
	// how much damage spells do
	int magicDamage;
	
	// consts for weapon damage
	const int HEAVY_DAMAGE = 20;
	const int MEDIUM_DAMAGE = 15;
	const int LIGHT_DAMAGE = 10;
	
	// bool for if character has shield active
	bool shieldActive;
	//bool for if character is healing
	bool healing;
	

	// protected member functions
	virtual void spellAttack(int t_attackTypeNumber);
	virtual void meleeAttack(int t_attackTypeNumber);
	virtual void shieldType(int t_attackTypeNumber);


	
	
};


#endif // !CHARACTER_H


