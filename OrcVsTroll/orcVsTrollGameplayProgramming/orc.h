///<summary>
///@author Cathal Redmond
///</summary>

#ifndef ORC_H
#define ORC_H

#include "character.h"

// orc class derived from character
class Orc : public Character
{
public:
	Orc(float t_orcIntialHealth = 100,
		float t_orcIntialStrength = 10,
		float t_orcIntialDefense = 10,
		float t_orcIntialSpeed = 12,
		float t_orcIntialEvasion = 80);
};

#endif // !ORC_H
