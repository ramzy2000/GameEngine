#include "MoveBackAction.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/VelocityComponent.h"
#include "Entity/Component/TransformComponent.h"
#include "Entity/Component/RigidBodyComponent.h"


void MoveBackAction::perform(ComponentManager& componentManager, Entity entity, sf::Time deltaTime)
{
	if (componentManager.hasComponent<VelocityComponent>(entity) && componentManager.hasComponent<TransformComponent>(entity))
	{
		TransformComponent& transformComponent = componentManager.getComponent<TransformComponent>(entity);
		VelocityComponent& velocityComponent = componentManager.getComponent<VelocityComponent>(entity);

		transformComponent.position.y = transformComponent.position.y + ((velocityComponent.GetVelocity()) * deltaTime.asSeconds());
	}
}
