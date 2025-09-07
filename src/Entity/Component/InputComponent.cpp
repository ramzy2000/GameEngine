#include "InputComponent.h"
#include "../Action/MoveForwardAction.h"
#include "../Action/MoveBackAction.h"
#include "../Action/MoveLeftAction.h"
#include "../Action/MoveRightAction.h"
#include <SFML/Graphics.hpp>

InputComponent::InputComponent()
{
	moveForwardAction = std::make_shared<MoveForwardAction>();
	moveBackAction = std::make_shared<MoveBackAction>();
	moveLeftAction = std::make_shared<MoveLeftAction>();
	moveRightAction = std::make_shared<MoveRightAction>();
}
