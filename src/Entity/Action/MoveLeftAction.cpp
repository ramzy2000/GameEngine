#include "MoveLeftAction.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/VelocityComponent.h"
#include "Entity/Component/TransformComponent.h"

void MoveLeftAction::perform(ComponentManager& componentManager, Entity entity, sf::Time deltaTime)
{
	TransformComponent& transformComponent = componentManager.getComponent<TransformComponent>(entity);
	VelocityComponent& velocityComponent = componentManager.getComponent<VelocityComponent>(entity);
	transformComponent.position.x = transformComponent.position.x + ((-velocityComponent.GetVelocity()) * deltaTime.asSeconds());
}
