#include "Actor.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/InputComponent.h"
#include "Entity/Component/PlayerInputComponent.h"
#include "Entity/Component/VelocityComponent.h"
#include "Game/GameData.h"

void Actor::generateId()
{
	// generate id
	this->entity_id = GameData::instance().entityManager.createNewEntity();
}

Actor::Actor()
{
	// get pointer to game data
	generateId();

	// give the actor a sprite component
	GameData::instance().componentManager.addComponent<SpriteComponent>(entity_id, SpriteComponent());
	SpriteComponent& spriteComponent = GameData::instance().componentManager.getComponent<SpriteComponent>(this->entity_id);
	spriteComponent.SetTexture(GameData::instance().assetManager.GetTexture("player_texture"));
}

Actor::~Actor()
{
	// delete entity and delete its components from component manager.
	GameData::instance().componentManager.removeAllComponents(entity_id);
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

Entity Actor::GetEntityId() const
{
	return entity_id;
}

const sf::Vector2f& Actor::GetPosition() const
{
	SpriteComponent& spriteComponent = GameData::instance().componentManager.getComponent<SpriteComponent>(GetEntityId());
	return spriteComponent.GetPosition();
}
