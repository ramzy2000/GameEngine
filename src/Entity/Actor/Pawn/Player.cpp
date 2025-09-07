#include "Player.h"
#include "../../Component/PlayerInputComponent.h"

Player::Player()
{
	this->addComponent<InputComponent>(std::make_shared<PlayerInputComponent>());
}
