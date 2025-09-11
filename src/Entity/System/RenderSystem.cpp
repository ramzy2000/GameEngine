#include "RenderSystem.h"
#include "../Component/SpriteComponent.h"
#include "../../Game/GameData.h"


void RenderSystem::update(ComponentManager& componentManager, std::vector<Entity> entities, sf::Time deltaTime)
{
	for (Entity entity : entities)
	{
		componentManager.getComponent<SpriteComponent>(entity).Draw(GameData::getRenderWindow());
	}
}
