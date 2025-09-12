#include "EntityManager.h"

Entity EntityManager::createNewEntity()
{
	// generate a unique
	Entity entity = index++;
	return entity;
}

void EntityManager::removeEntity(Entity entity)
{
	
}
