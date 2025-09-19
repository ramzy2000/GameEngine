#pragma once
#include "System.h"
class AnimationSystem : public System
{
public:
	void update(ComponentManager& componentManager, std::vector<Entity> entities, sf::Time deltaTime) override;
};

