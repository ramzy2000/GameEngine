#ifndef INPUT_COMPONENT
#define INPUT_COMPONENT

#include "../Action/Action.h"

class InputComponent
{
protected:
	std::shared_ptr<Action> moveForwardAction;
	std::shared_ptr<Action> moveBackAction;
	std::shared_ptr<Action> moveLeftAction;
	std::shared_ptr<Action> moveRightAction;
public:
	InputComponent();

	virtual std::vector<std::shared_ptr<Action>> HandleInput() = 0;
};

#endif // !INPUT_COMPONENT



