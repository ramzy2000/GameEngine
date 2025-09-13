#ifndef ENTITY_BASE_H
#define ENTITY_BASE_H
#include "Entity/Entity.h"
#include "Entity/Action/Action.h"
#include "Game/GameData.h"

class EntityBase
{
private:
	Entity entity_id;

	void generateId();
public:
	EntityBase();

	virtual ~EntityBase();

	Entity GetEntityId() const;
};

#endif // !ENTITY_BASE_H



