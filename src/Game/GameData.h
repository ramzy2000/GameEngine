#ifndef GAME_DATE_H
#define GAME_DATE_H
#include "Entity/System/InputSystem.h"
#include <stack>
#include "Entity/System/SystemManager.h"
#include "Entity/Component/ComponentManager.h"
#include "Game/AssetManager.h"
#include "Game/EntityManager.h"

class GameData
{
public:
	ComponentManager componentManager;
	EntityManager entityManager;
	AssetManager assetManager;
	std::shared_ptr<SystemManager> systemManager;
	static sf::RenderWindow window;
	//std::stack <std::shared_ptr<Level>> levels;
	std::vector<Entity> entities;
	bool isAdding = false;
	bool isRemoveing = false;

	static sf::RenderWindow& getRenderWindow();
};


#endif // !GAME_DATE_H
