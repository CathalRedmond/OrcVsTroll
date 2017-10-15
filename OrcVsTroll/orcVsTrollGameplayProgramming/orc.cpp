///<summary>
///@author Cathal Redmond
///</summary>

#include "orc.h"
//basic contstructor
Orc::Orc(float t_orcIntialHealth, 
	     float t_orcIntialStrength, 
		 float t_orcIntialDefense, 
		 float t_orcIntialSpeed, 
		 float t_orcIntialEvasion)
		
{
	health = t_orcIntialHealth;
	strength = t_orcIntialStrength;
	defense = t_orcIntialDefense;
	speed = t_orcIntialSpeed;
	evasion = t_orcIntialEvasion;
}
