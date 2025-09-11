#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "../Entity/Entity.h"
#include "../Entity//Component/ComponentManager.h"
#include <vector>

class EntityManager
{
	std::vector<Entity> entitys;
	std::unordered_map<std::size_t, Entity> indexToEntity;
	ComponentManager componentManager;
	std::size_t index = 0;
public:
	Entity createNewEntity();

	void removeEntity(Entity entity);
};

#endif //!ENTITY_MANAGER_Hs