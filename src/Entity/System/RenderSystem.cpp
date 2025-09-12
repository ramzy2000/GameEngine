#include "RenderSystem.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/DepthComponent.h"
#include "Game/GameData.h"


void RenderSystem::update(ComponentManager& componentManager, std::vector<Entity> entities, sf::Time deltaTime)
{
	// Sort by depth
	std::sort(entities.begin(), entities.end(), [&](Entity a, Entity b) {
		return componentManager.getComponent<DepthComponent>(a).depth < componentManager.getComponent<DepthComponent>(b).depth;
	});


	for (Entity entity : entities)
	{
		componentManager.getComponent<SpriteComponent>(entity).Draw(GameData::getRenderWindow());
	}
}
