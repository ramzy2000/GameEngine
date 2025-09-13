#include "Actor.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/InputComponent.h"
#include "Entity/Component/PlayerInputComponent.h"
#include "Entity/Component/VelocityComponent.h"
#include "Entity/Component/DepthComponent.h"
#include "Game/GameData.h"


Actor::Actor()
{
	// give the actor a sprite component
	GameData::instance().componentManager.addComponent<SpriteComponent>(GetEntityId(), SpriteComponent());
	SpriteComponent& spriteComponent = GameData::instance().componentManager.getComponent<SpriteComponent>(GetEntityId());
	spriteComponent.SetTexture(GameData::instance().assetManager.GetTexture("player_texture"));
	GameData::instance().componentManager.addComponent<DepthComponent>(GetEntityId(), DepthComponent());
}

void Actor::setPosition(const sf::Vector2f& position)
{
	SpriteComponent& spriteComponent = GameData::instance().componentManager.getComponent<SpriteComponent>(GetEntityId());
	spriteComponent.SetPosition(position);
}

void Actor::setPosition(const float& x, const float& y)
{
	SpriteComponent& spriteComponent = GameData::instance().componentManager.getComponent<SpriteComponent>(GetEntityId());
	spriteComponent.SetPosition(sf::Vector2f({x,y}));
}

const sf::Vector2f& Actor::GetPosition() const
{
	SpriteComponent& spriteComponent = GameData::instance().componentManager.getComponent<SpriteComponent>(GetEntityId());
	return spriteComponent.GetPosition();
}
