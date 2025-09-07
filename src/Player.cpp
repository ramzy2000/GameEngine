#include "Player.h"
#include "PlayerInputComponent.h"

Player::Player()
{
	this->addComponent<InputComponent>(std::make_shared<PlayerInputComponent>());
}
