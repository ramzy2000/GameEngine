#include "RenderSystem.h"
#include "SpriteComponent.h"

void RenderSystem::update(sf::RenderWindow* window, sf::Time deltaTime)
{
	for (std::shared_ptr<Entity> entity : entities)
	{
		entity->getComponent<SpriteComponent>()->Draw(*window);
	}
}
