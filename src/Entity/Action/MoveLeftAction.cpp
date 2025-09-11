#include "MoveLeftAction.h"
#include "../Component/SpriteComponent.h"
#include "../Component/VelocityComponent.h"

void MoveLeftAction::perform(ComponentManager& componentManager, Entity entity, sf::Time deltaTime)
{
	if (componentManager.hasComponent<VelocityComponent>(entity) && componentManager.hasComponent<SpriteComponent>(entity))
	{
		SpriteComponent& spriteComponent = componentManager.getComponent<SpriteComponent>(entity);
		VelocityComponent& velocityComponent = componentManager.getComponent<VelocityComponent>(entity);
		spriteComponent.Move(sf::Vector2f({ -velocityComponent.GetVelocity() * deltaTime.asSeconds(), 0.0f }));
	}
}
