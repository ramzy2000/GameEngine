#include "CameraSystem.h"
#include "../Component/CameraComponent.h"
#include "../Component/SpriteComponent.h"
#include "../../Game/GameData.h"

void CameraSystem::update(ComponentManager& componentManager, std::vector<Entity> entities, sf::Time deltaTime)
{
	for (auto& entity : entities)
	{
		if (componentManager.hasComponent<CameraComponent>(entity) && componentManager.hasComponent<SpriteComponent>(entity))
		{
			SpriteComponent spriteComponent = componentManager.getComponent<SpriteComponent>(entity);
			CameraComponent cameraComponent = componentManager.getComponent<CameraComponent>(entity);
			cameraComponent.GetView().setCenter(spriteComponent.GetPosition() + cameraComponent.GetOffset());
			GameData::getRenderWindow().setView(cameraComponent.GetView());
		}
	}
}