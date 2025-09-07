#include "SystemManager.h"

SystemManager::SystemManager(std::shared_ptr<GameData> gameData)
{
	this->gameData = gameData;
}

void SystemManager::Update(std::shared_ptr<Entity> entity, sf::Time deltaTime)
{
    // update all systems for this entity
}
