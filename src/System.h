#ifndef SYSTEM_H
#define SYSTEM_H
#include <memory>
#include "Entity.h"
#include <SFML/Graphics.hpp>

class System
{
public:
	virtual ~System() = default;
	void addEntity(std::shared_ptr<Entity> entity);
	virtual void update(sf::Time deltaTime) = 0;
	void clearEntities();
protected:
	std::vector<std::shared_ptr<Entity>> entities;
};

inline void System::addEntity(std::shared_ptr<Entity> entity)
{
	entities.push_back(entity);
}

inline void System::clearEntities()
{
	entities.clear();
}

#endif SYSTEM_H