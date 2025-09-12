#include "Pawn.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/InputComponent.h"
#include "Entity/Component/PlayerInputComponent.h"
#include "Entity/Component/VelocityComponent.h"
#include <iostream>

Pawn::Pawn(std::shared_ptr<GameData> gameData) : Actor(gameData)
{
	gameData->componentManager.addComponent<VelocityComponent>(GetEntityId(), VelocityComponent());
}
