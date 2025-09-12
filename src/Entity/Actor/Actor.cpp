#include "Actor.h"
#include "../Component/SpriteComponent.h"
#include "../Component/InputComponent.h"
#include "../Component/PlayerInputComponent.h"
#include "../Component/VelocityComponent.h"

void Actor::generateId()
{
	// generate id
	this->entity_id = gameData->entityManager.createNewEntity();
}

Actor::Actor(std::shared_ptr<GameData> gameData)
{
	// get pointer to game data
	this->gameData = gameData;
	generateId();

	// give the actor a sprite component
	gameData->componentManager.addComponent<SpriteComponent>(entity_id, SpriteComponent());
	SpriteComponent& spriteComponent = gameData->componentManager.getComponent<SpriteComponent>(this->entity_id);
	spriteComponent.SetTexture(this->gameData->assetManager.GetTexture("player_texture"));
}

Actor::~Actor()
{
	// delete entity and delete its components from component manager.
	gameData->componentManager.removeAllComponents(entity_id);
}

void Actor::setPosition(const sf::Vector2f& position)
{
	SpriteComponent& spriteComponent = gameData->componentManager.getComponent<SpriteComponent>(GetEntityId());
	spriteComponent.SetPosition(position);
}

void Actor::setPosition(const float& x, const float& y)
{
	SpriteComponent& spriteComponent = gameData->componentManager.getComponent<SpriteComponent>(GetEntityId());
	spriteComponent.SetPosition(sf::Vector2f({x,y}));
}

Entity Actor::GetEntityId() const
{
	return entity_id;
}

const sf::Vector2f& Actor::GetPosition() const
{
	SpriteComponent& spriteComponent = gameData->componentManager.getComponent<SpriteComponent>(GetEntityId());
	return spriteComponent.GetPosition();
}
