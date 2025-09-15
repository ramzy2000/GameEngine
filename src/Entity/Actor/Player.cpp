#include "Player.h"

#include "Entity/Component/PlayerInputComponent.h"
#include "Entity/Component/CameraComponent.h"
#include "Entity/Component/VelocityComponent.h"
#include "Entity/Component/RigidBodyComponent.h"
#include "Entity/Component/CollisionComponent.h"
#include "Game/GameData.h"

Player::Player() : Pawn()
{
	GameData::instance().componentManager.addComponent<PlayerInputComponent>(GetEntityId(), PlayerInputComponent());
	GameData::instance().componentManager.addComponent<CameraComponent>(GetEntityId(), CameraComponent());

	GameData::instance().componentManager.addComponent<VelocityComponent>(GetEntityId(), VelocityComponent());
	GameData::instance().componentManager.addComponent<RigidBodyComponent>(GetEntityId(), RigidBodyComponent());
	GameData::instance().componentManager.addComponent<CollisionComponent>(GetEntityId(), CollisionComponent());
	CollisionComponent& collisionComponent = GameData::instance().componentManager.getComponent<CollisionComponent>(GetEntityId());
	collisionComponent.size.x = 100;
	collisionComponent.size.y = 200;
	GameData::instance().systemManager->physicsSystem.createBody(GameData::instance().componentManager, GetEntityId());

	RigidBodyComponent& rigidBodyComponent = GameData::instance().componentManager.getComponent<RigidBodyComponent>(GetEntityId());
	rigidBodyComponent.body->SetLinearDamping(100.f);
}
