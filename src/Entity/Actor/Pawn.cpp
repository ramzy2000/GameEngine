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
	GameData::instance().componentManager.addComponent<VelocityComponent>(GetEntityId(), VelocityComponent());
	GameData::instance().componentManager.addComponent<RigidBodyComponent>(GetEntityId(), RigidBodyComponent());
	GameData::instance().componentManager.addComponent<CollisionComponent>(GetEntityId(), CollisionComponent());
	GameData::instance().systemManager->physicsSystem.createBody(GameData::instance().componentManager, GetEntityId());

	RigidBodyComponent& rigidBodyComponent = GameData::instance().componentManager.getComponent<RigidBodyComponent>(GetEntityId());
	rigidBodyComponent.body->SetLinearDamping(100.f);
}
