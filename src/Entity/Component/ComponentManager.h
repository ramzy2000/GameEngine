#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <unordered_map>
#include <vector>
#include <bitset>
#include <typeindex>
#include <memory>
#include <cassert>
#include "Entity/Entity.h"
#include "Entity/Component/IComponentArray.h"
#include "Entity/Component/ComponentArray.h"

constexpr std::size_t MAX_COMPONENTS = 64;
using Signature = std::bitset<MAX_COMPONENTS>;

class ComponentManager
{
    std::unordered_map<std::type_index, std::unique_ptr<IComponentArray>> componentArrays;
    std::unordered_map<Entity, Signature> entitySignatures;

    // Component type ID system
    inline static std::size_t nextComponentTypeID = 0;
    std::unordered_map<std::type_index, std::size_t> componentTypeIDs;

    template<typename T>
    ComponentArray<T>* getArray() const
    {
        std::type_index type = typeid(T);
        auto it = componentArrays.find(type);
        assert(it != componentArrays.end() && "Component Not Registered");
        return static_cast<ComponentArray<T>*>(it->second.get());
    }

    template<typename T>
    std::size_t getComponentTypeID()
    {
        std::type_index type = typeid(T);
        auto it = componentTypeIDs.find(type);
        if (it == componentTypeIDs.end())
        {
            std::size_t id = nextComponentTypeID++;
            assert(id < MAX_COMPONENTS && "Exceeded max component types");
            componentTypeIDs[type] = id;
            return id;
        }
        return it->second;
    }

public:
    template<typename T>
    void registerComponent()
    {
        std::type_index type = typeid(T);
        assert(componentArrays.find(type) == componentArrays.end() && "Component already registered.");
        componentArrays[type] = std::make_unique<ComponentArray<T>>();
        getComponentTypeID<T>(); // Assign ID
    }

    template<typename T>
    void addComponent(Entity entity, T component)
    {
        getArray<T>()->insert(entity, component);
        entitySignatures[entity].set(getComponentTypeID<T>());
    }

    template<typename T>
    void removeComponent(Entity entity)
    {
        getArray<T>()->remove(entity);
        entitySignatures[entity].reset(getComponentTypeID<T>());
    }

    template<typename T>
    T& getComponent(Entity entity)
    {
        return getArray<T>()->get(entity);
    }

    template<typename T>
    bool hasComponent(Entity entity) const
    {
        auto it = entitySignatures.find(entity);
        if (it == entitySignatures.end()) return false;
        std::type_index type = typeid(T);
        auto idIt = componentTypeIDs.find(type);
        if (idIt == componentTypeIDs.end()) return false;
        return it->second.test(idIt->second);
    }

    void removeAllComponents(Entity entity)
    {
        for (auto& [type, array] : componentArrays)
        {
            array->remove(entity);
        }
        entitySignatures.erase(entity);
    }

    // 🔍 Fast query using bitmask signature
    template<typename... Components>
    std::vector<Entity> GetEntities()
    {
        Signature required;
        (required.set(getComponentTypeID<Components>()), ...); // Fold expression

        std::vector<Entity> result;
        for (const auto& [entity, signature] : entitySignatures)
        {
            if ((signature & required) == required)
            {
                result.push_back(entity);
            }
        }

        return result;
    }
};

#endif // COMPONENT_MANAGER_H