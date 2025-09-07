#include "RenderSystem.h"
#include "../Component/SpriteComponent.h"

void RenderSystem::update(sf::RenderWindow* window, std::shared_ptr<Entity> entity, sf::Time deltaTime)
{
	entity->getComponent<SpriteComponent>()->Draw(*window);
}
