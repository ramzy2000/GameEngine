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
	spriteComponent.SetTexture("../Textures/Player.png");
}

Actor::~Actor()
{
	// delete entity and delete its components from component manager.
	gameData->componentManager.removeAllComponents(entity_id);
}

Entity Actor::GetEntityId() const
{
	return entity_id;
}
