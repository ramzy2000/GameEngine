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
		assert(it != componentArrays.end() && "Component Not Registered");
		return static_cast<ComponentArray<T>*>(it->second.get());
	}

public:
    template<typename T>
    void registerComponent()
    {
        std::type_index type = typeid(T);
        assert(componentArrays.find(type) == componentArrays.end() && "Component already registered.");
        componentArrays[type] = std::make_unique<ComponentArray<T>>();
    }

    template<typename T>
    void addComponent(Entity entity, T component) 
    {
        getArray<T>()->insert(entity, component);
    }

    template<typename T>
    void removeComponent(Entity entity) 
    {
        getArray<T>()->remove(entity);
    }

    template<typename T>
    T& getComponent(Entity entity) 
    {
        return getArray<T>()->get(entity);
    }

    template<typename T>
    bool hasComponent(Entity entity) const 
    {
        return getArray<T>()->has(entity);
    }

    void removeAllComponents(Entity entity)
    {
        for (auto& [type, array] : componentArrays)
        {
            array->remove(entity);
        }
    }
};

#endif //!COMPONENT_MANAGER_H