#include "SystemManager.h"

#include "Game/GameData.h"

SystemManager::SystemManager(std::shared_ptr<GameData> gameData)
{
	this->gameData = gameData;
}

void SystemManager::Update(sf::Time deltaTime)
{
    // update all systems for this entity
	inputSystem.update(gameData->componentManager, gameData->entities, deltaTime);
	cameraSystem.update(gameData->componentManager, gameData->entities, deltaTime);
	renderSystem.update(gameData->componentManager, gameData->entities, deltaTime);
}
