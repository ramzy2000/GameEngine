#ifndef MOVE_LEFT_ACTION_H
#define MOVE_LEFT_ACTION_H

#include "Action.h"
class MoveLeftAction : public Action
{
public:
	void perform(std::shared_ptr<Entity> entity, sf::Time deltaTime) override;
};

#endif //! MOVE_LEFT_ACTION_H