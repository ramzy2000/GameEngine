#pragma once
#include "Action.h"

class MoveForwardAction : public Action
{
public:
	void perform(std::shared_ptr<Entity> entity, sf::Time deltaTime) override;
};

