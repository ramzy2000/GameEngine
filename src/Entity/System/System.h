#ifndef SYSTEM_H
#define SYSTEM_H
#include <memory>
#include "Entity/Entity.h"
#include <SFML/Graphics.hpp>

#include "Entity/Component/ComponentManager.h"

class System
{
public:
	virtual ~System() = default;
	virtual void update(ComponentManager& componentManager, std::vector<Entity> entities, sf::Time deltaTime) = 0;
};

#endif SYSTEM_H