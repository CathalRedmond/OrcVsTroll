///<summary>
///@author Cathal Redmond
///</summary>

#include "shield.h"

// outputs different shield options player can preform and generally what they do
void Shield::outputOptions() const
{
	std::cout << "Which Shield Would You Like To Use?" << std::endl;
	std::cout << "1). Pure Shield" << std::endl;
	std::cout << "You take no damage this turn" << std::endl;
	std::cout << "2). Magic Shield" << std::endl;
	std::cout << "Enemy Takes Magic Damage If They Hit You but you still take damage" << std::endl;
	std::cout << "3). Spiked Shield" << std::endl;
	std::cout << "Enemy Takes Damage If They Hit You but you still take damage" << std::endl;

}
