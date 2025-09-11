#ifndef COMPONENT_ARRAY_H
#define COMPONENT_ARRAY_H

#include <vector>
#include <unordered_map>
#include <cassert>
#include "IComponentArray.h"

template<typename T>
class ComponentArray : public IComponentArray
{
private:
	std::vector<T> components;
	std::unordered_map<Entity, std::size_t> entityToIndex;
	std::unordered_map<std::size_t, Entity> indexToEntity;
public:
	void insert(Entity entity, T component)
	{
		// insert the entity
		assert(entityToIndex.find(entity) == entityToIndex.end() && "Component already exists");
		std::size_t index = components.size(); // get current index
		entityToIndex[entity] = index;
		indexToEntity[index] = entity;
		components.push_back(component);
	}

	void remove(Entity entity) override
	{
		auto it = entityToIndex.find(entity);
		if (it == entityToIndex.end())
		{
			return; // no entity found.
		}

		std::size_t index = it->second;
		std::size_t lastIndex = components.size() - 1;

		components[index] = components[lastIndex];
		Entity lastEntity = indexToEntity[lastIndex];

		entityToIndex[lastEntity] = index;
		indexToEntity[index] = lastEntity;
	}

	T& get(Entity entity)
	{
		return components[entityToIndex[entity]];
	}

	bool has(Entity entity) const
	{
		return (entityToIndex.find(entity) != entityToIndex.end());
	}
};

#endif COMPONENT_ARRAY_H