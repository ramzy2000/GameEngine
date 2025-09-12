#ifndef INPUT_COMPONENT
#define INPUT_COMPONENT

#include "Entity/Action/Action.h"

class InputComponent
{
protected:
	std::shared_ptr<Action> moveForwardAction;
	std::shared_ptr<Action> moveBackAction;
	std::shared_ptr<Action> moveLeftAction;
	std::shared_ptr<Action> moveRightAction;
public:
	InputComponent();

	virtual std::vector<std::shared_ptr<Action>> HandleInput() { return std::vector<std::shared_ptr<Action>>(); }
};

#endif // !INPUT_COMPONENT



