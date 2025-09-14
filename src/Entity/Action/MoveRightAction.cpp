#include "MoveRightAction.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/VelocityComponent.h"
#include "Entity/Component/TransformComponent.h"

void MoveRightAction::perform(ComponentManager& componentManager, Entity entity, sf::Time deltaTime)
{
	if (componentManager.hasComponent<VelocityComponent>(entity) && componentManager.hasComponent<TransformComponent>(entity))
	{
		TransformComponent& transformComponent = componentManager.getComponent<TransformComponent>(entity);
		VelocityComponent& velocityComponent = componentManager.getComponent<VelocityComponent>(entity);

		transformComponent.position.x = transformComponent.position.x + ((velocityComponent.GetVelocity()) * deltaTime.asSeconds());
	}
}