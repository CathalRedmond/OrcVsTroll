///<summary>
///@author Cathal Redmond
///</summary>

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "melee.h"
#include "shield.h"
#include "spell.h"
#include "orc.h"
#include "troll.h"
#include <ctime>
#include <cstdlib>
#include <string>

// struct for loot table
// allows for upgrades to be bought with coins earned
struct lootMenu
{
	static const int NO_OF_UPGRADES = 3;
	int upgrades[NO_OF_UPGRADES] = {1,1,1};
};

// main game class of the game
class Game
{
public:
	// allows program to run
	void run();
protected:
	// protected member functions

	void choosingRace();
	void callLootTable();
	void menu();
	void movement();
	void outputMovement() const;
	void enemyAppear();
	void treasureAppear();
	void fight();
	void gameOver() const;
	void outputCharactersHealth() const;
	void battle();
	void choosingAction();
	void checkEvasion();


	// protected data members
	// bool for if player killed themselves
	bool suicide = false;

	// instances for orc, troll and charcter pointers to each
	Troll troll;
	Orc orc;
	Character *player = &orc;
	Character *enemy = &troll;

	// instances for shield, spell , melee , action classes and a action pointer to each
	Melee melee;
	Spell spell;
	Shield shield;
	Action action;
	Action *choosenAction = &action;
	
	// instance of lootmenu struct
	lootMenu lootLoot;

	// variable for item picked in main menui
	int menuChoice = 0;
	// int for which direction player is moving
	int direction = 0;
	// int for danger counter 
	// higher it is higher chance enemys will appear
	int dangerCounter = 0;
	// int for treasure counter
	// higher it is higher chance of finding gold
	int treasureCounter = 0;
	// int for number of enemys killed/defeated
	int enemysKilled = 0;
	
};

#endif // !GAME_H

//void checkStatusEffects();