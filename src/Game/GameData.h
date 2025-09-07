#ifndef GAME_DATE_H
#define GAME_DATE_H
#include "../Entity/System/InputSystem.h"
#include "../Entity/System/RenderSystem.h"
#include "../Level/Level.h"
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
