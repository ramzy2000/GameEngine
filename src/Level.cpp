#include "Level.h"
#include "SpriteComponent.h"

void Level::SpawnEntity(std::shared_ptr<Entity> entity, sf::Vector2f position)
{
	// set the entity position
	std::shared_ptr<SpriteComponent> spriteComponent = entity->getComponent<SpriteComponent>();
	spriteComponent->SetPosition(position);
	// add entity to level
	entities.push_back(entity);
}

void Level::DestoryEntity(std::shared_ptr<Entity> entitie)
{
	entities.remove(entitie);
}

std::list<std::shared_ptr<Entity>>& Level::GetList()
{
	return this->entities;
}
