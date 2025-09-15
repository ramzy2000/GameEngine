#include "Pawn.h"
#include "Entity/Component/SpriteComponent.h"
#include "Entity/Component/InputComponent.h"
#include "Entity/Component/PlayerInputComponent.h"
#include "Entity/Component/VelocityComponent.h"
#include "Entity/Component/RigidBodyComponent.h"
#include "Entity/Component/TransformComponent.h"
#include "Entity/Component/CollisionComponent.h"
#include "Game/GameData.h"
#include <iostream>

Pawn::Pawn() : Actor()
{
	GameData::instance().componentManager.addComponent<SpriteComponent>(GetEntityId(), SpriteComponent());
	SpriteComponent& spriteComponent = GameData::instance().componentManager.getComponent<SpriteComponent>(GetEntityId());
	spriteComponent.SetTexture(GameData::instance().assetManager.GetTexture("assassin_texture"));
}
