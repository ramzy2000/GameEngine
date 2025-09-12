#include "MoveForwardAction.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/VelocityComponent.h"
#include <iostream>

void MoveForwardAction::perform(ComponentManager& componentManager, Entity entity, sf::Time deltaTime)
{
	if (componentManager.hasComponent<VelocityComponent>(entity) && componentManager.hasComponent<SpriteComponent>(entity))
	{
		SpriteComponent& spriteComponent = componentManager.getComponent<SpriteComponent>(entity);
		VelocityComponent& velocityComponent = componentManager.getComponent<VelocityComponent>(entity);
		spriteComponent.Move(sf::Vector2f({ 0.0f, -1*(velocityComponent.GetVelocity() * deltaTime.asSeconds()) }));
	}
}