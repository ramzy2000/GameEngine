#include "Pawn.h"
#include "../Component/SpriteComponent.h"
#include "../Component/InputComponent.h"
#include "../Component/PlayerInputComponent.h"
#include "../Component/VelocityComponent.h"

Pawn::Pawn(std::shared_ptr<GameData> gameData) : Actor(gameData)
{
	gameData->componentManager.addComponent<VelocityComponent>(GetEntityId(), VelocityComponent());
}
