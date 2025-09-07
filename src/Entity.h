#ifndef ENTITYH
#define ENTITYH
#include <memory>
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <typeinfo>

class Entity
{
protected:
	std::unordered_map<std::type_index, std::shared_ptr<void>> components;
public:
	template <typename T>
	void addComponent(std::shared_ptr<T> component)
	{
		components[typeid(T)] = component;
	}

	template <typename T>
	std::shared_ptr<T> getComponent() const
	{
		auto it = components.find(typeid(T));
		if (it != components.end())
		{
			return std::static_pointer_cast<T>(it->second);
		}
		return nullptr;
	}
};

#endif // !ENTITYH_H

