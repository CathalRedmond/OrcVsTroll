///<summary>
///@author Cathal Redmond
///</summary>

#ifndef SHIELD_H
#define SHIELD_H

#include "action.h"
// inherited class from action
// class that outputs shield options to the player
class Shield : public Action
{
public:
	void outputOptions() const;
};

#endif // !SHIELD_H