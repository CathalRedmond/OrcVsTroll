///<summary>
///@author Cathal Redmond
///</summary>

#include "game.h"

void Game::run()
{

	srand(time(nullptr));
	choosingRace();
	
	// repeats while player is alive
	while (((player->getHealth()) > 0) && !suicide)
	{
		menu();
	}
	gameOver();
	system("pause");
}


// function that allows player to upgrade
void Game::callLootTable()
{
	// resets value
	menuChoice = 0;
	int choice = 0;
	// repeats until correct value is entered
	while (choice == 0)
	{
		std::cout << "You're current amount of Gold is " << player->getGold() << " coins" << std::endl;
		std::cout << "What would you like to buy? ( All cost 5 coins)" << std::endl;
		std::cout << "1). Strength Upgrade Level " << lootLoot.upgrades[0] << std::endl;
		std::cout << "2). Defense Upgrade Level " << lootLoot.upgrades[1] << std::endl;
		std::cout << "3). Speed Upgrade Level " << lootLoot.upgrades[2] << std::endl;
		std::cin >> choice;
		// if player doesn't have enough gold nothing happens
		if (player->getGold() >= 5)
		{
			// increases upgrade level of chosen upgrade
			// upgrades corresponding stat and takes away necessary gold
			switch (choice)
			{
			case 1:
				lootLoot.upgrades[0]++;
				player->upgradeStats(1);
				player->changeGold(-5);
				break;
			case 2:
				lootLoot.upgrades[1]++;
				player->upgradeStats(2);
				player->changeGold(-5);
				break;
			case 3:
				lootLoot.upgrades[2]++;
				player->upgradeStats(3);
				player->changeGold(-5);
				break;
				
			default:
				std::cout << std::endl;
				// if one of the correct options arent picked player doesn't upgrade
				std::cout << "You have upgraded nothing" << std::endl;
				choice = 0;
				break;
			}
		}
	}
}

// function that allows player to use the menu
void Game::menu()
{
	// resets value
	menuChoice = 0;
	// repeats until correct value is entered
	while (menuChoice == 0)
	{
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "1). Explore the area (movement)" << std::endl;
		std::cout << "2). Access the loot menu " << std::endl;
		std::cout << "3). End it all" << std::endl;
		std::cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			movement();
			break;
		case 2:
			callLootTable();
			break;
		case 3:
			suicide = true;
			break;
		default:
			menuChoice = 0;
			break;
		}
	}
	
}

// function that allows player to choose if they want 
// to be an orc or troll
void Game::choosingRace()
{
	int chosenRace = 0;
	// repeats until correct value is entered
	while(chosenRace == 0)
	{
		std::cout << "Do you wish to be a" << std::endl;
		std::cout << "1). Troll or 2). Orc" << std::endl;
		std::cin >> chosenRace;
		// sets value to 0 if wrong number is inputted
		if (chosenRace != 1 && chosenRace != 2)
		{
			chosenRace = 0;
		}
	}
	if (chosenRace == 1)
	{
		player = &troll;
		enemy = &orc;
		std::cout << "You are a Troll"<< std::endl;
	}
	else
	{
		player = &orc;
		enemy = &troll;
		std::cout << "You are an Orc" << std::endl;

	}

	player->setHealth(100);
	enemy->setHealth(100);
}

// function that allows player to move
void Game::movement()
{
	std::cout << "Which way do you want to move?" << std::endl;
	std::cout << "1). North" << std::endl;
	std::cout << "2). South" << std::endl;
	std::cout << "3). East" << std::endl;
	std::cout << "4). West" << std::endl;
	std::cin >> direction;
	
	// if incorrect value won't work
	if (direction == 1 || direction == 2 || direction == 3 || direction == 4)
	{
		treasureCounter++;
		dangerCounter++;
	}
	outputMovement();
	//only works if player hasn't killed themselves
	if (!suicide)
	{
		enemyAppear();
		treasureAppear();
	}
	std::cout << std::endl;
}

// outputs which direction player is moving
void Game::outputMovement() const
{
	switch(direction)
	{
	case 1:
		std::cout << "Heading North" << std::endl;
		break;
	case 2:
		std::cout << "Heading South" << std::endl;
		break;
	case 3:
		std::cout << "Heading East" << std::endl;
		break;
	case 4:
		std::cout << "Heading West" << std::endl;
		break;
	default:
		std::cout << "Staying Still" << std::endl;
		break;
	}
}

// function that determines if enemy appears or not
void Game::enemyAppear()
{
	// random number between 1 and 100
	int randomNumber = rand() % 100 + 1;
	//
	if (randomNumber < (dangerCounter * 10))
	{
		std::cout << "Enemy is Approaching" << std::endl;
		// enemy appearing leads to a fight
		fight();
		dangerCounter = 0;
	}
	else
	{
		std::cout << "All Clear Ahead" << std::endl;
	}
	std::cout << std::endl;
}


// function that determines if enemy appears or not
void Game::treasureAppear()
{
	// random number between 1 and 100
	int randomNumber = rand() % 100 + 1;
	if (randomNumber < (treasureCounter * 5))
	{
		std::cout << "You have found treasure" << std::endl;
		std::cout << "Plus " << treasureCounter << " Gold" << std::endl;
		player->changeGold(treasureCounter);
		treasureCounter = 0;
	}
	else
	{
		std::cout << "Area is barren" << std::endl;
	}
}

// outputs gameover screen
void Game::gameOver() const
{
	// if player killed themselves
	if (suicide)
	{
		std::cout << "Having grown tired of your life you decided to end it all" << std::endl;
	}
	else
	{
		std::cout << "During the game you defeated " << enemysKilled << " enemies" << std::endl;
		std::cout << "and found " << player->getGold() << " gold" << std::endl;
	}
	std::cout << "Game Over - You're Dead" << std::endl;

}

// function for when enemy attacks
void Game::fight()
{
	// fight loops until either player or enemy is dead
	while (enemy->getHealth() > 0 && player->getHealth() > 0)
	{
		outputCharactersHealth();
		choosingAction();
		battle();
	}
	// resets enemy health after fight and increases gold amount
	if (enemy->getHealth() <= 0)
	{
		enemy->setHealth(100);
		std::cout << "You have gained 5 gold for killing enemy" << std::endl;
		player->changeGold(5);
	}
}

void Game::battle()
{
	// intialises enemys damage
	enemy->enemyAttack();
	// calculates damage done by player and enemy for this turn
	player->calculateDamage(enemy->getDefense());
	enemy->calculateDamage(player->getDefense());


	checkEvasion();

	// character deals no damage while healing
	if (player->isHealing())
	{
		player->setDamage(0);
		player->changeHealth(10);

	}
	else if (enemy->isHealing())
	{
		enemy->setDamage(0);
		enemy->changeHealth(10);
	}
	// opponent deals no damage if character shieled
	if (player->isShieldActive())
	{
		enemy->setDamage(0);
	}
	else if (enemy->isShieldActive())
	{
		player->setDamage(0);
	}

	// checks which character has higher speed stat
	// higher stat deals damage first
	if ((player->getSpeed()) > (enemy->getSpeed()))
	{
		enemy->changeHealth(player->getDamage());
		if (enemy->getHealth() > 0)
		{
			player->changeHealth(enemy->getDamage());
		}

	}
	else
	{
		player->changeHealth(enemy->getDamage());
		if (player->getHealth() > 0)
		{
			enemy->changeHealth(player->getDamage());
		}
	}



	std::cout << std::endl;
	// checks if enemy missed player
	if (enemy->getDamage() == 0)
	{
		if ((!player->isShieldActive()) && (!enemy->isHealing()) && (enemy->getHealth() > 0))	// exceptions to if statement
		{
			std::cout << "Enemy Has Missed the Player" << std::endl;
		}
	}
	// checks if player missed enemy
	else if (player->getDamage() == 0)
	{
		if ((enemy->isShieldActive()) && (!player->isHealing()) && (player->getHealth() > 0))	// exceptions to if statement
		{
			std::cout << "Player Has Missed The Enemy" << std::endl;
		}
	}
}

// function thats allows player to choose attack type
void Game::choosingAction()
{
	int inputtedNumber = 0;
	choosenAction = &action;
	// repeats until correct value is entered
	while (inputtedNumber == 0)
	{
		choosenAction->outputOptions();
		// chooses between shield spell and melee
		std::cin >> inputtedNumber;
		switch (inputtedNumber)
		{
		case 1:
			choosenAction = &melee;
			break;
		case 2:
			choosenAction = &spell;
			break;
		case 3:
			choosenAction = &shield;
			break;
		default:
			inputtedNumber = 0;
			break;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	choosenAction->outputOptions();
	int choice;
	// choses bewteen specific(spell melee shield) attack type
	std::cin >> choice;
	player->attack(inputtedNumber, choice);
}

// checks if character has evaded and if they do the other characters attack is set to 0
void Game::checkEvasion()
{
	if (player->getEvasion())
	{
		enemy->setDamage(0);
	}
	else if(enemy->getEvasion())
	{
		player->setDamage(0);
	}
}




// function that outputs player and enemys health to screen
void Game::outputCharactersHealth() const
{
	std::cout << std::endl;
	std::cout << "Player Health: " << player->getHealth() << "\t Enemy Health: " << enemy->getHealth() << std::endl;
	std::cout << std::endl;
}



