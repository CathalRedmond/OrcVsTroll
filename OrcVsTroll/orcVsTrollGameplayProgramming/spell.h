///<summary>
///@author Cathal Redmond
///</summary>

#ifndef SPELL_H
#define SPELL_H

#include "action.h"

// inherited class from action
// class that outputs spell options to the player
class Spell : public Action
{
public:
	void outputOptions() const;
}; 


#endif // !SPELL_H