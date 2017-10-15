///<summary>
///@author Cathal Redmond
///</summary>

#include "spell.h"

// outputs different spell attacks player can preform and what they do
void Spell::outputOptions() const
{
	std::cout << "Which Spell would you like to cast?" << std::endl;
	std::cout << "1). Fire" << std::endl;
	std::cout << "Deals Fire Damage" << std::endl;
	std::cout << "2). Ice" << std::endl;
	std::cout << "Deals Ice Damage" << std::endl;
	std::cout << "3). Poison" << std::endl;
	std::cout << "Deals Poison Damage" << std::endl;
	std::cout << "4). Thunder" << std::endl;
	std::cout << "Deals Thunder Damage" << std::endl;
	std::cout << "5). Heal" << std::endl;
	std::cout << "Heals Players Health" << std::endl;
}
