#ifndef PHYSICS_SYSTEM_H
#define PHYSICS_SYSTEM_H

#include "System.h"
#include "Game/PhysicsWorld.h"

class PhysicsSystem : public System
{
	PhysicsWorld physicsWorld;
public:
	void update(ComponentManager& componentManager, std::vector<Entity> entities, sf::Time deltaTime) override;
	void createBody(ComponentManager& componentManager, Entity entity);
};

#endif //! PHYSICS_SYSTEM_H