#ifndef MOVE_BACK_ACTION
#define MOVE_BACK_ACTION

#include "Action.h"
#include "../Component/ComponentManager.h"

class MoveBackAction : public Action
{
public:
	void perform(ComponentManager& componentManager, Entity entity, sf::Time deltaTime) override;
};

#endif MOVE_BACK_ACTION