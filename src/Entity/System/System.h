#ifndef SYSTEM_H
#define SYSTEM_H
#include <memory>
#include "../Entity.h"
#include <SFML/Graphics.hpp>

class System
{
public:
	virtual ~System() = default;
	virtual void update(std::shared_ptr<Entity> entity, sf::Time deltaTime) = 0;
};

#endif SYSTEM_H