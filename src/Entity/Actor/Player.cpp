#include "Player.h"

#include "../Component/PlayerInputComponent.h"
#include "../Component/CameraComponent.h"

Player::Player(std::shared_ptr<GameData> gameData) : Pawn(gameData)
{
	gameData->componentManager.addComponent<PlayerInputComponent>(GetEntityId(), PlayerInputComponent());
	gameData->componentManager.addComponent<CameraComponent>(GetEntityId(), CameraComponent());
}
