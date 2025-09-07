#include "InputComponent.h"
#include "MoveForwardAction.h"
#include "MoveBackAction.h"
#include "MoveLeftAction.h"
#include "MoveRightAction.h"
#include <SFML/Graphics.hpp>

InputComponent::InputComponent()
{
	moveForwardAction = std::make_shared<MoveForwardAction>();
	moveBackAction = std::make_shared<MoveBackAction>();
	moveLeftAction = std::make_shared<MoveLeftAction>();
	moveRightAction = std::make_shared<MoveRightAction>();
}
