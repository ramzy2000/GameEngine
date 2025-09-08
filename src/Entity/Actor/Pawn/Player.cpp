#include "Player.h"
#include "../../Component/PlayerInputComponent.h"
#include "../../Component/CameraComponent.h"

Player::Player()
{
	this->addComponent<InputComponent>(std::make_shared<PlayerInputComponent>());
	this->addComponent<CameraComponent>(std::make_shared<CameraComponent>());
}
