#include "MoveBackAction.h"
#include "../Component/SpriteComponent.h"
#include "../Component/VelocityComponent.h"


void MoveBackAction::perform(ComponentManager& componentManager, Entity entity, sf::Time deltaTime)
{
	if (componentManager.hasComponent<VelocityComponent>(entity) && componentManager.hasComponent<SpriteComponent>(entity))
	{
		SpriteComponent& spriteComponent = componentManager.getComponent<SpriteComponent>(entity);
		VelocityComponent& velocityComponent = componentManager.getComponent<VelocityComponent>(entity);
		spriteComponent.Move(sf::Vector2f({ 0.0f, velocityComponent.GetVelocity() * deltaTime.asSeconds() }));
	}
}
