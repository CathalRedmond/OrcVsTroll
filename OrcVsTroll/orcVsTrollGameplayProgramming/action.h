///<summary>
///@author Cathal Redmond
///</summary>

#ifndef ACTION_H
#define ACTION_H

#include <iostream>

// class that outputs attacks options to the player
class Action
{
public:
	virtual void outputOptions() const;
};

#endif	// !ACTION_H