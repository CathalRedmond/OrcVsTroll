///<summary>
///@author Cathal Redmond
///</summary>

#include "melee.h"

// outputs different melee actions player can preform in battle and generally what they do
void Melee::outputOptions() const
{
	std::cout << "Which Melee Attack Would You Like To Do?" << std::endl;
	std::cout << "1). Sword" << std::endl;
	std::cout << "Medium Weapon Damage" << std::endl;
	std::cout << "2). Daggers" << std::endl;
	std::cout << "Light Weapon Damage" << std::endl;
	std::cout << "3). Axe" << std::endl;
	std::cout << "Medium Weapon Damage" << std::endl;
	std::cout << "4). Fist" << std::endl;
	std::cout << "Light weapon Damage" << std::endl;
	std::cout << "5). Spear" << std::endl;
	std::cout << "Medium Weapon Damage" << std::endl;
	std::cout << "6). WarAxe" << std::endl;
	std::cout << "Heavy Weapon Damage" << std::endl;
	std::cout << "7). Mace" << std::endl;
	std::cout << "Heavy Weapon Damage" << std::endl;
}
