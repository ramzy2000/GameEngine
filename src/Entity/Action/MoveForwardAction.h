#pragma once
#include "Action.h"

class MoveForwardAction : public Action
{
public:
	void perform(ComponentManager& componentManager, Entity entity, sf::Time deltaTime) override;
};

