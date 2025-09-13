#include "EntityBase.h"

EntityBase::EntityBase()
{
	// generate id
	this->entity_id = GameData::instance().entityManager.createNewEntity();
}

EntityBase::~EntityBase()
{
	// delete entity and delete its components from component manager.
    GameData::instance().componentManager.removeAllComponents(entity_id);
}

Entity EntityBase::GetEntityId() const
{
	return entity_id;
}