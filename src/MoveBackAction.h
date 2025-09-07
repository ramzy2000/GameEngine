#ifndef MOVE_BACK_ACTION
#define MOVE_BACK_ACTION

#include "Action.h"

class MoveBackAction : public Action
{
public:
	void perform(std::shared_ptr<Entity> entity, sf::Time deltaTime) override;
};

#endif MOVE_BACK_ACTION