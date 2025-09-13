#include "RenderSystem.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/DepthComponent.h"
#include "Entity/Component/TransformComponent.h"
#include "Game/GameData.h"


void RenderSystem::update(ComponentManager& componentManager, std::vector<Entity> entities, sf::Time deltaTime)
{
	// Sort by depth
	std::sort(entities.begin(), entities.end(), [&](Entity a, Entity b) {
		return componentManager.getComponent<DepthComponent>(a).depth < componentManager.getComponent<DepthComponent>(b).depth;
	});


	for (Entity entity : entities)
	{
		SpriteComponent& spriteComponent = componentManager.getComponent<SpriteComponent>(entity);
		TransformComponent& transformComponent = componentManager.getComponent<TransformComponent>(entity);

		std::optional<sf::Sprite>& sprite = spriteComponent.sprite;
		sprite->setPosition(transformComponent.position);
		sprite->setRotation(sf::radians(transformComponent.rotation));
		sprite->setScale(transformComponent.scale);

		componentManager.getComponent<SpriteComponent>(entity).Draw(GameData::getRenderWindow());
	}
}
