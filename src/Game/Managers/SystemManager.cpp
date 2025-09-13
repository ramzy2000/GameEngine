#include "SystemManager.h"
#include "Entity/Component/PlayerInputComponent.h"
#include "Entity/Component/CameraComponent.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/DepthComponent.h"
#include "Entity/Component/RigidBodyComponent.h"
#include "Entity/Component/CollisionComponent.h"
#include "Entity/Component/TransformComponent.h"
#include "Game/GameData.h"


SystemManager::SystemManager()
{
	
}

void SystemManager::Update(sf::Time deltaTime)
{
    // update all systems for this entity
	inputSystem.update(GameData::instance().componentManager, GameData::instance().componentManager.GetEntities<PlayerInputComponent>(), deltaTime);
	cameraSystem.update(GameData::instance().componentManager, GameData::instance().componentManager.GetEntities<CameraComponent>(), deltaTime);
	renderSystem.update(GameData::instance().componentManager, GameData::instance().componentManager.GetEntities<SpriteComponent, DepthComponent, TransformComponent>(), deltaTime);
	physicsSystem.update(GameData::instance().componentManager, GameData::instance().componentManager.GetEntities<RigidBodyComponent, CollisionComponent, TransformComponent>(), deltaTime);
}
