#ifndef LEVEL_H
#define LEVEL_H
#include <memory>
#include <list>
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "InputSystem.h"
#include "RenderSystem.h"

class Level
{
protected:
	std::list<std::shared_ptr<Entity>> entities;
;
	bool isPaused = false;
public:
	// Spawn Entity
	void SpawnEntity(std::shared_ptr<Entity> entity, sf::Vector2f position);

	// destory entity
	void DestoryEntity(std::shared_ptr<Entity> entitie);

	std::list<std::shared_ptr<Entity>>& GetList();
};

#endif // !LEVEL_H