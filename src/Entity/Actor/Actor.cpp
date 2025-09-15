#include "Actor.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/InputComponent.h"
#include "Entity/Component/PlayerInputComponent.h"
#include "Entity/Component/VelocityComponent.h"
#include "Entity/Component/DepthComponent.h"
#include "Entity/Component/TransformComponent.h"
#include "Entity/Component/RigidBodyComponent.h"
#include "Game/GameData.h"


Actor::Actor()
{
	// give the actor a sprite component
	GameData::instance().componentManager.addComponent<TransformComponent>(GetEntityId(), TransformComponent());
	GameData::instance().componentManager.addComponent<DepthComponent>(GetEntityId(), DepthComponent());
}

void Actor::setPosition(const sf::Vector2f& position)
{
	if (GameData::instance().componentManager.hasComponent<RigidBodyComponent>(GetEntityId()))
	{
		RigidBodyComponent& rigidBodyComponent = GameData::instance().componentManager.getComponent<RigidBodyComponent>(GetEntityId());
		if (rigidBodyComponent.body)
		{
			rigidBodyComponent.body->SetTransform(b2Vec2({ position.x/100, position.y / 100 }), 0.0f);
		}
	}

	TransformComponent& transformComponent = GameData::instance().componentManager.getComponent<TransformComponent>(GetEntityId());
	transformComponent.position = position;
}

void Actor::setPosition(const float& x, const float& y)
{
	if (GameData::instance().componentManager.hasComponent<RigidBodyComponent>(GetEntityId()))
	{
		RigidBodyComponent& rigidBodyComponent = GameData::instance().componentManager.getComponent<RigidBodyComponent>(GetEntityId());
		if (rigidBodyComponent.body)
		{
			rigidBodyComponent.body->SetTransform(b2Vec2({ x/100, y/100 }), 0.0f);
		}
	}

	TransformComponent& transformComponent = GameData::instance().componentManager.getComponent<TransformComponent>(GetEntityId());
	transformComponent.position = sf::Vector2f({x, y});
}

const sf::Vector2f& Actor::GetPosition() const
{
	TransformComponent& transformComponent = GameData::instance().componentManager.getComponent<TransformComponent>(GetEntityId());
	return transformComponent.position;
}
