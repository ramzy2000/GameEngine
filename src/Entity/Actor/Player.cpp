#include "Player.h"

#include "Entity/Component/PlayerInputComponent.h"
#include "Entity/Component/CameraComponent.h"

Player::Player(std::shared_ptr<GameData> gameData) : Pawn(gameData)
{
	gameData->componentManager.addComponent<PlayerInputComponent>(GetEntityId(), PlayerInputComponent());
	gameData->componentManager.addComponent<CameraComponent>(GetEntityId(), CameraComponent());
}
