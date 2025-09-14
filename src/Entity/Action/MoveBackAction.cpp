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
		
		if (componentManager.hasComponent<RigidBodyComponent>(entity))
		{
			RigidBodyComponent& rigidBodyComponent = componentManager.getComponent<RigidBodyComponent>(entity);

			// move the rigid body
			if (rigidBodyComponent.body)
			{
				rigidBodyComponent.body->ApplyLinearImpulse(b2Vec2({ 0.0f, -velocityComponent.GetVelocity() / 10000 }), rigidBodyComponent.body->GetWorldCenter(), true);
			}
		}
	}
}
