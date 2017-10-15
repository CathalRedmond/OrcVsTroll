///<summary>
///@author Cathal Redmond
///</summary>

#include "action.h"

// outputs different in battle actions player can preform
void Action::outputOptions() const
{
	std::cout << "What Do You Wish To Do?" << std::endl;
	std::cout << "1). Melee Attack Enemy" << std::endl;
	std::cout << "2). Cast Spell" << std::endl;
	std::cout << "3). Defend " << std::endl;
}
