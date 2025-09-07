#ifndef MOVE_RIGHT_ACTION_H
#define MOVE_RIGHT_ACTION_H


#include "Action.h"

class MoveRightAction : public Action
{
public:
	void perform(std::shared_ptr<Entity> entity, sf::Time deltaTime) override;
};

#endif // !MOVE_RIGHT_ACTION_H



