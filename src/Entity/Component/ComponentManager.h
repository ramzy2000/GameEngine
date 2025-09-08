#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <unordered_map>
#include <vector>
#include "../Entity.h"
#include "../Component/IComponentArray.h"
#include "../Component/ComponentArray.h"
#include <typeindex>
#include <cassert>

class ComponentManager
{
	std::unordered_map<std::type_index, std::unique_ptr<IComponentArray>> componentArrays;

	template<typename T>
	ComponentArray<T>* getArray() const
	{
		std::type_index type = typeid(T);
		auto it = componentArrays.find(type);
		assert(it != it.end() && "Component Not Registered");
		return static_cast<ComponentArray<T>*>(it->second.get());
	}

public:

};

#endif //!COMPONENT_MANAGER_H