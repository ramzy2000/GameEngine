#include "Player.h"

#include "Entity/Component/PlayerInputComponent.h"
#include "Entity/Component/CameraComponent.h"
#include "Game/GameData.h"

Player::Player() : Pawn()
{
	GameData::instance().componentManager.addComponent<PlayerInputComponent>(GetEntityId(), PlayerInputComponent());
	GameData::instance().componentManager.addComponent<CameraComponent>(GetEntityId(), CameraComponent());
}
