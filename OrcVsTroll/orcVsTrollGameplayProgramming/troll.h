///<summary>
///@author Cathal Redmond
///</summary>

#ifndef TROLL_H
#define TROLL_H

#include "character.h"

// troll class derived form character
class Troll : public Character
{
public:
	Troll(float t_trollIntialHealth = 100,
		  float t_trollIntialStrength = 12,
		  float t_trollIntialDefense = 12,
		  float t_trollIntialSpeed = 10,
		  float t_trollIntialEvasion = 90);
};

#endif // !TROLL_H