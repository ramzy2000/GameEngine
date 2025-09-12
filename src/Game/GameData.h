#ifndef GAME_DATE_H
#define GAME_DATE_H
#include "Entity/System/InputSystem.h"
#include <stack>
#include "Game/Managers/SystemManager.h"
#include "Game/Managers/ComponentManager.h"
#include "Game/Managers/AssetManager.h"
#include "Game/Managers/EntityManager.h"

class GameData
{
private:
	GameData() = default;
	~GameData() = default;
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

	GameData(const GameData&) = delete;
	GameData& operator=(const GameData&) = delete;

	static GameData& instance() {
		static GameData instance;
		return instance;
	}

	static sf::RenderWindow& getRenderWindow();
};


#endif // !GAME_DATE_H
