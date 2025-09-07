#ifndef PLAYER_INPUT_COMPONENT_H
#define PLAYER_INPUT_COMPONENT_H

#include "InputComponent.h"

class PlayerInputComponent : public InputComponent
{
public:
	PlayerInputComponent();

	std::vector<std::shared_ptr<Action>> HandleInput() override;
};

#endif // PLAYER_INPUT_COMPONENT_H

