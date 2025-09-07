#ifndef GAME_DATE_H
#define GAME_DATE_H
#include "../Entity/System/InputSystem.h"
#include "../Level/Level.h"
#include <stack>
#include "../Entity/System/SystemManager.h"

class GameData
{
public:
	std::shared_ptr<SystemManager> systemManager;
	sf::RenderWindow window;
	std::stack <std::shared_ptr<Level>> levels;
	bool isAdding = false;
	bool isRemoveing = false;
};


#endif // !GAME_DATE_H
