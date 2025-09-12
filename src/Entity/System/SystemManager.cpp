#include "SystemManager.h"
#include "Entity/Component/PlayerInputComponent.h"
#include "Entity/Component/CameraComponent.h"
#include "Entity/Component/SpriteComponent.h"

#include "Game/GameData.h"

SystemManager::SystemManager(std::shared_ptr<GameData> gameData)
{
	this->gameData = gameData;
}

void SystemManager::Update(sf::Time deltaTime)
{
    // update all systems for this entity
	
	inputSystem.update(gameData->componentManager, gameData->componentManager.GetEntities<PlayerInputComponent>(), deltaTime);
	cameraSystem.update(gameData->componentManager, gameData->componentManager.GetEntities<CameraComponent>(), deltaTime);
	renderSystem.update(gameData->componentManager, gameData->componentManager.GetEntities<SpriteComponent>(), deltaTime);
}
