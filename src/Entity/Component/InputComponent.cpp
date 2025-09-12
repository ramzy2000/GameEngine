#include "InputComponent.h"
#include "Entity/Action/MoveForwardAction.h"
#include "Entity/Action/MoveBackAction.h"
#include "Entity/Action/MoveLeftAction.h"
#include "Entity/Action/MoveRightAction.h"
#include <SFML/Graphics.hpp>

InputComponent::InputComponent()
{
	moveForwardAction = std::make_shared<MoveForwardAction>();
	moveBackAction = std::make_shared<MoveBackAction>();
	moveLeftAction = std::make_shared<MoveLeftAction>();
	moveRightAction = std::make_shared<MoveRightAction>();
}
