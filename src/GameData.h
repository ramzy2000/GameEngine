#ifndef GAME_DATE_H
#define GAME_DATE_H
#include "InputSystem.h"
#include "RenderSystem.h"
#include "Level.h"
#include <stack>

class GameData
{
public:
	InputSystem inputSystem;
	RenderSystem renderSystem;
	std::stack <std::shared_ptr<Level>> levels;
	bool isAdding = false;
	bool isRemoveing = false;
};


#endif // !GAME_DATE_H
