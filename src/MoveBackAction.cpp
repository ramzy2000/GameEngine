#include "MoveBackAction.h"
#include "SpriteComponent.h"
#include "VelocityComponent.h"

void MoveBackAction::perform(std::shared_ptr<Entity> entity, sf::Time deltaTime)
{
	std::shared_ptr<SpriteComponent> spriteComponent = entity->getComponent<SpriteComponent>();
	std::shared_ptr<VelocityComponent> velocityComponent = entity->getComponent<VelocityComponent>();
	if (spriteComponent && velocityComponent)
	{
		spriteComponent->Move(sf::Vector2f({ 0.0f, velocityComponent->GetVelocity() * deltaTime.asSeconds() }));
	}
}
