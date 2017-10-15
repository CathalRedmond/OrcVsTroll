///<summary>
///@author Cathal Redmond
///</summary>

#ifndef MELEE_H
#define MELEE_H

#include "action.h"
// inherited class from action
// class that outputs attacks melee to the player
class Melee : public Action
{
public:
	void outputOptions() const;
};

#endif // !MELLE_H