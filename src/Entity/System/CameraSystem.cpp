#include "CameraSystem.h"
#include "Entity/Component/CameraComponent.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/TransformComponent.h"
#include "Game/GameData.h"

void CameraSystem::update(ComponentManager& componentManager, std::vector<Entity> entities, sf::Time deltaTime)
{
	for (auto& entity : entities)
	{
		TransformComponent transformComponent = componentManager.getComponent<TransformComponent>(entity);
		CameraComponent cameraComponent = componentManager.getComponent<CameraComponent>(entity);
		cameraComponent.GetView().setCenter(transformComponent.position + cameraComponent.GetOffset());
		GameData::getRenderWindow().setView(cameraComponent.GetView());
	}
}