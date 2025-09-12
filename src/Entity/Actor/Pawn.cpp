#include "Pawn.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/InputComponent.h"
#include "Entity/Component/PlayerInputComponent.h"
#include "Entity/Component/VelocityComponent.h"
#include "Game/GameData.h"
#include <iostream>

Pawn::Pawn() : Actor()
{
	GameData::instance().componentManager.addComponent<VelocityComponent>(GetEntityId(), VelocityComponent());
}
