///<summary>
///@author Cathal Redmond
///</summary>

#include "troll.h"
//basic contstructor
Troll::Troll(float t_trollIntialHealth, 
			 float t_trollIntialStrength, 
			 float t_trollIntialDefense, 
			 float t_trollIntialSpeed, 
			 float t_trollIntialEvasion)
{
	health = t_trollIntialHealth;
	strength = t_trollIntialStrength;
	defense = t_trollIntialDefense;
	speed = t_trollIntialSpeed;
	evasion = t_trollIntialEvasion;
}
