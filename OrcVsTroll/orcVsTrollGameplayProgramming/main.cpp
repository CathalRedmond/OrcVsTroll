///<summary>
///@mainPage - Orc vs Troll Game
///@Author Cathal Redmond
///
/// Orc vs troll game where player plays as
/// either orc or troll and fights the other 
/// while gaining loot
///
/// uses encapsulation inheritance and polymorphism
/// </summary>
 

#include "game.h"


// main function of the game
int main(){
	Game game;
	game.run();
}





































/*int chooseAction()
{
	int i;
	std::cout << "What character do you want to be?" << std::endl;
	std::cout << "1). Orc" << std::endl;
	std::cout << "2). Troll " << std::endl;
	std::cin >> i;
	if (i == 1)
	{
		std::cout << "You have chosen Orc" << std::endl;
	}
	else if (i == 2)
	{
		std::cout << "You have chosen Troll" << std::endl;
	}
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1). Attack Enemy with Weapon" << std::endl;
	std::cout << "2). Cast a Spell" << std::endl;
	std::cout << "3). Raise a Shield" << std::endl;
	int choice = 0;
	std::cin >> choice;
	return choice;
}

int chooseSpellType()
{
	
	int type = 0;
	std::cin >> type;
	return type;
}

int chooseMeleeType()
{

	std::cout << "Which Melee Attack Would You Like To Do?" << std::endl;
	std::cout << "1). Sword" << std::endl;
	std::cout << "2). Daggers" << std::endl;
	std::cout << "3). Axe" << std::endl;
	std::cout << "4). Fist" << std::endl;
	std::cout << "5). Spear" << std::endl;
	std::cout << "6). Bow" << std::endl;
	std::cout << "7). Gun" << std::endl;
	int type = 0;
	std::cin >> type;
	return type;
}

int chooseShieldType()
{

	
	int type = 0;
	std::cin >> type;
	return type;
}

int choosetype(int number)
{
	int fds;
	switch (number)
	{
	case 1:
		fds = chooseMeleeType();
		break;
	case 2:
		fds = chooseSpellType();
		break;
	case 3:
		fds = chooseShieldType();
		break;
	default:
		break;
	}
	return fds;
}*/


