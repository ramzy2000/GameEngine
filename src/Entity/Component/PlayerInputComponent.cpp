#include "PlayerInputComponent.h"

PlayerInputComponent::PlayerInputComponent()
{

}

std::vector<std::shared_ptr<Action>> PlayerInputComponent::HandleInput()
{
	std::vector<std::shared_ptr<Action>> actions;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		actions.push_back(moveForwardAction);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		actions.push_back(moveBackAction);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		actions.push_back(moveLeftAction);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		actions.push_back(moveRightAction);
	}
	return actions;
}
